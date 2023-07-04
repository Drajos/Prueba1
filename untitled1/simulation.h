
#ifndef UNTITLED1_SIMULATION_H
#define UNTITLED1_SIMULATION_H

#include <stdio.h>
#include <math.h>
#include "structures.h"
#include "answer_structure.h"

#define G 6.67430e-11

double calculateExcentricity(double perihelionDistance, double aphelionDistance);
double calculateOrbitalRadius(double semimajorAxis, double excentricity, double eccentricAnomaly);
void calculateCoordinates(const Object* object, const Query* query, double* x, double* y);
answer* startSimulation(ObjectNode* objectList, QueryNode* queryList);

#endif //UNTITLED1_SIMULATION_H
