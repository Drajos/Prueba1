

#ifndef UNTITLED1_FILE_MANAGER_H
#define UNTITLED1_FILE_MANAGER_H

#include "structures.h"
#include "answer_structure.h"

char* getFileName();
Object* getObjectList(char *fileName);
Query * getQueryList(char *fileName);
void saveAnswerList(answerNode* head);


#endif //UNTITLED1_FILE_MANAGER_H
