#include "answer_structure.h"

/**
 * Insert an answer at the end of the list
 * @param head answerNode**
 * @param answer answer
 */
void insertAnswer(answerNode** head, answer answer){
    answerNode* newNode = (answerNode*)malloc(sizeof(answerNode));
    newNode->answer = answer;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        answerNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

/**
 * Print the answer list
 * @param head
 */
void printAnswerList(answerNode* head){
    answerNode* current = head;
    while (current != NULL) {
        printf("ID de consulta: %s\n", current->answer.queryID);
        printf("Posición X: %lf\n", current->answer.x);
        printf("Posición Y: %lf\n", current->answer.y);
        printf("\n");
        current = current->next;
    }
}

/**
 * Free the answer list
 * @param head
 */
void freeAnswerList(answerNode* head){
    answerNode* current = head;
    answerNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

