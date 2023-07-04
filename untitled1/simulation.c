#include "simulation.h"

/**
 * Calculates the excentricity of an orbit given its perihelion and aphelion distances.
 * @param perihelionDistance double
 * @param aphelionDistance double
 * @return double
 */
double calculateExcentricity(double perihelionDistance, double aphelionDistance) {
    return (aphelionDistance - perihelionDistance) / (aphelionDistance + perihelionDistance);
}

/**
 * Calculates the orbital radius of an object given its semimajor axis, excentricity and eccentric anomaly.
 * @param semimajorAxis double
 * @param excentricity double
 * @param eccentricAnomaly double
 * @return double
 */
double calculateOrbitalRadius(double semimajorAxis, double excentricity, double eccentricAnomaly) {
    return semimajorAxis * (1 - excentricity * cos(eccentricAnomaly));
}

/**
 * Calculates the coordinates of an object given its orbital parameters and the time since its perihelion.
 * @param object Object*
 * @param query Query*
 * @param x double*
 * @param y double*
 */
void calculateCoordinates(const Object* object, const Query* query, double* x, double* y) {

    double semimajorAxis = (object->aphelionX - object->perihelionX) / 2.0;
    double excentricity = calculateExcentricity(object->perihelionX, object->aphelionX);
    double angularVelocity = sqrt(G * object->mass / pow(semimajorAxis, 3));

    double timeSincePerihelion = query->timeInSeconds;

    double meanAnomaly = angularVelocity * timeSincePerihelion;
    double eccentricAnomaly = meanAnomaly;

    // Iteratively solve for eccentric anomaly
    double previousEccentricAnomaly;
    do {
        previousEccentricAnomaly = eccentricAnomaly;
        eccentricAnomaly = eccentricAnomaly - (eccentricAnomaly - excentricity * sin(eccentricAnomaly) - meanAnomaly) /
                                              (1 - excentricity * cos(eccentricAnomaly));
    } while (fabs(eccentricAnomaly - previousEccentricAnomaly) > 1e-6);

    double orbitalRadius = calculateOrbitalRadius(semimajorAxis, excentricity, eccentricAnomaly);

    *x = object->perihelionX + orbitalRadius * cos(eccentricAnomaly);
    *y = object->perihelionY + orbitalRadius * sin(eccentricAnomaly);
}

/**
 * Starts the simulation given a list of objects and a list of queries.
 * @param objectList ObjectNode*
 * @param queryList QueryNode*
 * @return answer*
 */
answer* startSimulation(ObjectNode* objectList, QueryNode* queryList) {

    QueryNode* currentQuery = queryList;
    answer* answerList = NULL;

    while (currentQuery != NULL) {

        Object* object = getObject(objectList, currentQuery->query.objectID);

        double x, y;
        calculateCoordinates(object, &currentQuery->query, &x, &y);

        answer answer;
        strcpy(answer.queryID, currentQuery->query.queryID);
        answer.x = x;
        answer.y = y;

        insertAnswer(&answerList, answer);

        currentQuery = currentQuery->next;
    }

    return answerList;

}