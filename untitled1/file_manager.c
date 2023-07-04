#include "file_manager.h"

/**
 * Request the file name to the user and return it
 * @return
 */
char* getFileName(){
    char* fileName = malloc(sizeof(char) * 50);
    printf("Ingrese el nombre del archivo a leer (debe estar en la carperta files): ");
    scanf("%s", fileName);
    strcat(fileName, ".txt");

    char filePath[50] = "./files/";
    strcat(filePath, fileName);
    strcpy(fileName, filePath);


    return fileName;
}

/**
 * Read the file and return a list of objects
 * @param fileName char*
 * @return Object*
 */
Object* getObjectList(char *fileName){

    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    char line[256];
    Object *objectList = NULL;

    while (fgets(line, sizeof(line), file)) {
        // Separar los campos de la línea
        char* token;
        char* field[8];
        int i = 0;
        token = strtok(line, ";");
        while (token != NULL) {
            field[i++] = token;
            token = strtok(NULL, ";");
        }

        // Almacenar los datos en las estructuras correspondientes
        if (i == 8) {
            Object obj;
            strcpy(obj.objectID, field[0]);
            obj.mass = atof(field[1]);
            obj.perihelionX = atof(field[2]);
            obj.perihelionY = atof(field[3]);
            obj.aphelionX = atof(field[4]);
            obj.aphelionY = atof(field[5]);
            obj.initialPosX = atof(field[6]);
            obj.initialPosY = atof(field[7]);
            insertObject(&objectList, obj);
        }
    }

    fclose(file);

    return objectList;

}

/**
 * Read the file and return a list of queries
 * @param fileName char*
 * @return Query*
 */
Query * getQueryList(char *fileName){

    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    char line[256];
    Query * queryList = NULL;

    while (fgets(line, sizeof(line), file)) {
        // Separar los campos de la línea
        char* token;
        char* field[8];
        int i = 0;
        token = strtok(line, ";");
        while (token != NULL) {
            field[i++] = token;
            token = strtok(NULL, ";");
        }

        if (i == 3) {
            Query query;
            strcpy(query.queryID, field[0]);
            strcpy(query.objectID, field[1]);
            query.timeInSeconds = atof(field[2]);
            insertQuery(&queryList, query);
        }
    }

    fclose(file);

    return queryList;

}

/**
 * Save the answer list in a file
 * @param head answerNode*
 */

void saveAnswerList(answerNode* head){

    FILE *file = fopen("./files/respuestas.txt", "w");

    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    answerNode* current = head;

    while (current != NULL){
        fprintf(file, "%s;%f;%f\n", current->answer.queryID, current->answer.x, current->answer.y);
        current = current->next;
    }

    fclose(file);

}

