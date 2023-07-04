#ifndef UNTITLED1_ANSWER_STRUCTURE_H
#define UNTITLED1_ANSWER_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char queryID[50];
    double x;
    double y;
} answer;

typedef struct answerNode {
    answer answer;
    struct answerNode* next;
} answerNode;

void insertAnswer(answerNode** head, answer answer);
void printAnswerList(answerNode* head);
void freeAnswerList(answerNode* head);

#endif //UNTITLED1_ANSWER_STRUCTURE_H
