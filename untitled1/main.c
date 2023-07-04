#include <stdio.h>
#include "structures.h"
#include "file_manager.h"
#include "answer_structure.h"
#include "simulation.h"

int main() {

    Object* objectList = NULL;
    Query * queryList = NULL;
    answer * answerList = NULL;

    char* fileName = getFileName();

    objectList = getObjectList(fileName);
    queryList = getQueryList(fileName);

    answerList = startSimulation(objectList, queryList);

    saveAnswerList(answerList);

    freeObjectList(objectList);
    freeQueryList(queryList);
    freeAnswerList(answerList);

    return 0;
}