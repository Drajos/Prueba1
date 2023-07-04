#include "structures.h"

/**
 * Insert an object at the end of the list
 * @param head ObjectNode**
 * @param object Object
 */
void insertObject(ObjectNode** head, Object object) {
    ObjectNode* newNode = (ObjectNode*)malloc(sizeof(ObjectNode));
    newNode->object = object;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ObjectNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

/**
 * Insert a query at the end of the list
 * @param head QueryNode**
 * @param query Query
 */
void insertQuery(QueryNode** head, Query query) {
    QueryNode* newNode = (QueryNode*)malloc(sizeof(QueryNode));
    newNode->query = query;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        QueryNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

/**
 * Print the object list
 * @param head ObjectNode*
 */
void printObjectList(ObjectNode* head) {
    ObjectNode* current = head;
    while (current != NULL) {
        printf("ID: %s\n", current->object.objectID);
        printf("Masa: %lf\n", current->object.mass);
        printf("Perihelion X: %lf\n", current->object.perihelionX);
        printf("Perihelion Y: %lf\n", current->object.perihelionY);
        printf("Aphelion X: %lf\n", current->object.aphelionX);
        printf("Aphelion Y: %lf\n", current->object.aphelionY);
        printf("Posición inicial X: %lf\n", current->object.initialPosX);
        printf("Posición inicial Y: %lf\n", current->object.initialPosY);
        printf("\n");
        current = current->next;
    }
}

/**
 * Print the query list
 * @param head QueryNode*
 */
void printQueryList(QueryNode* head) {
    QueryNode* current = head;
    while (current != NULL) {
        printf("ID de consulta: %s\n", current->query.queryID);
        printf("ID de objeto consultado: %s\n", current->query.objectID);
        printf("Tiempo en segundos: %lf\n", current->query.timeInSeconds);
        printf("\n");
        current = current->next;
    }
}

/**
 * Free the memory used by the object list
 * @param head ObjectNode*
 */
void freeObjectList(ObjectNode* head) {
    ObjectNode* current = head;
    ObjectNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

/**
 * Free the memory used by the query list
 * @param head QueryNode*
 */
void freeQueryList(QueryNode* head) {
    QueryNode* current = head;
    QueryNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

/**
 * Get the object with the given ID
 * @param head ObjectNode*
 * @param objectID char*
 * @return Object*
 */
Object* getObject(ObjectNode* head, char* objectID){
    ObjectNode* current = head;
    while (current != NULL) {
        if (strcmp(current->object.objectID, objectID) == 0) {
            return &current->object;
        }
        current = current->next;
    }
    return NULL;
}
