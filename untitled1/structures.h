#ifndef UNTITLED1_STRUCTURES_H
#define UNTITLED1_STRUCTURES_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char objectID[50];
    double mass;
    double perihelionX;
    double perihelionY;
    double aphelionX;
    double aphelionY;
    double initialPosX;
    double initialPosY;
} Object;

typedef struct {
    char queryID[50];
    char objectID[50];
    double timeInSeconds;
} Query;

typedef struct ObjectNode {
    Object object;
    struct ObjectNode* next;
} ObjectNode;

typedef struct QueryNode {
    Query query;
    struct QueryNode* next;
} QueryNode;

void insertObject(ObjectNode** head, Object object);
void insertQuery(QueryNode** head, Query query);
void printObjectList(ObjectNode* head);
void printQueryList(QueryNode* head);
void freeObjectList(ObjectNode* head);
void freeQueryList(QueryNode* head);
Object* getObject(ObjectNode* head, char* objectID);

#endif //UNTITLED1_STRUCTURES_H
