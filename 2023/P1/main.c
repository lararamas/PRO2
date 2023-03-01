/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: LARA RAMAS MARIÑO          LOGIN 1: lara.ramas
 * AUTHOR 2: ÁNGELA CLEMENTE LÓPEZ      LOGIN 2: angela.clemente
 * GROUP: 3.2
 * DATE: 04 / 03 / 2022
 */

#include <stdio.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

/*
 * OBJETIVO: convertir la cadena de caracteres leída desde el fichero en un tEUParticipant (boleano)
 * ENTRADA: cadena de caracteres
 * SALIDA: tEUParticipant
 * PRE-CD:
 * POST-CD*/

tEUParticipant convertCategory(char *categoria){

    if( strcmp(categoria, "eu") == 0 ){
        return true;
    }else{
        return false;
    }

}

char* category(bool categoria){

    if(categoria==true){
        return "eu";
    }else{
        return "non-eu";
    }

}

/*
 * OBJETIVO: dar de alta un nuevo participante de ser posible, es decir, si el participante con ese nombre no existe.
 * ENTRADA: una lista tList, un participantName, EUParticipant, todos cadenas de caracteres.
 * SALIDA: una lista tList con el participante insertado y su información de haberse dado el alta, si no un mensaje de error y la lista tal cual entró.
 * PRE-CD: se asume que los nombres no exceden el límite de caracteres
 * POST-CD: los elementos que ya estaban en la lista pueden haber cambiado de posición.
 * */
void new(char *participantName, char *EUParticipant, tList *L) {
    tItemL item;

    strcpy(item.participantName, participantName);
    item.EUParticipant= convertCategory(EUParticipant);
    item.numVotes=0;

    if(findItem(participantName, *L) != LNULL || insertItem(item, LNULL, L) == false ){ //si la lista está llena
        printf("+ Error: New not possible\n");
    }else{
        printf("* New: participant %s location %s \n",participantName, EUParticipant);
    }
}


/*
 * OBJETIVO: incrementar el contador de votos del participante votado de ser posible, es decir si el nombre exite en la lista o si esta no está vacía.
 * ENTRADA: una lista tList, un participantName, EUParticipant, todos cadenas de caracteres.
 * SALIDA: una lista tList en el que el participante aparece con un voto a mayores, si no un mensaje de error y la lista tal cual entró.
 * PRE-CD: se asume que los votos no exceden el límite
 * POST-CD: los elementos que ya estaban en la lista pueden haber cambiado de posición.
 * */

void vote(char *participantName, tList *list, int *votonull) {
    tPosL pos;
    tItemL item;

    if(!isEmptyList(*list)){
        //existe el participante
        if((pos = findItem(participantName, *list)) == LNULL){
            votonull++;
        }
        else
            item = getItem(pos, *list);
        item.numVotes += 1;
        printf("+ Vote: participant %s location %s numvotes %d\n", item.participantName, category(item.EUParticipant), item.numVotes);

    }
    else
        *votonull++;

}

/*
 * OBJETIVO: se busca al participante en la lista y se borra pasando sus votos como votos nulos
 * ENTRADA: una lista tList, un participantName, int votonull.
 * SALIDA: una lista tList en el que el participante no aparece en la lista.
 * PRE-CD: se asume que los votos no exceden el límite
 * POST-CD: los elementos que ya estaban en la lista pueden haber cambiado de posición.
 * */
void disqualify(char *participantName, tList *list, int *votonull) {

    if(!isEmptyList(*list)){
        tPosL p = findItem(participantName,*list);

        if( p != LNULL){

            tItemL borrado = getItem(p,*list);
            printf("* Disqualify: participant %s location %s \n",borrado.participantName, category(borrado.EUParticipant));
            *votonull += borrado.numVotes;
            deleteAtPosition(p,list);

        }else{
            printf("+ Error: Disqualify not possible\n");
        }
    } else{
        printf("+ Error: Disqualify not possible\n");
    }
}


float totalvotos(tList L, int votonull){

    float total=0;
    tItemL objeto;

    for(tPosL i = first(L); i != LNULL; i = next(i,L)){
        objeto = getItem(i,L);
        total+= objeto.numVotes;
    }

    return total+votonull;
}


/*
 * OBJETIVO: se muestra la lista complenta de participantes y su porcentaje de votos.
 * ENTRADA: una lista tList, un totalvoters, int votonull.
 * SALIDA: lista completa de participantes y su porcentaje de votos
 * PRE-CD: se asume que los votos no exceden el límite
 * POST-CD:
 * */

void stats(char *totalvoters, tList list, int votonull) {
    if(isEmptyList(list)){ //si la lista de participantes está vacía, significa que lo está toda la lista

        printf("+ Error: Stats not possible\n");

    }else{
        tPosL i;
        float tot;
        float por;
        float totalv = (float) strtol(totalvoters, NULL, 10);
        for( i = first(list); i != LNULL; i = next(i, list) ){
            tItemL d = getItem(i, list); //item que corresponde a la posición que se va moviendo
            tot = totalvotos(list, votonull);
            por = ((float)d.numVotes/ tot) * 100;
            if(d.numVotes != 0)
                printf("Participant %s location %s numvotes %d (%2.f%%)\n", d.participantName, category(d.EUParticipant),d.numVotes,por);
            else
                printf("Participant %s location %s numvotes %d (0.00%%)\n", d.participantName, category(d.EUParticipant),d.numVotes);

        }
        por = ((float)totalvotos(list, votonull)/(float)totalv) * 100;
        printf("Null votes %d\n", votonull);
        printf("Participation:%.0f votes from %.0f voters (%.2f)%%\n", totalvotos(list, votonull), totalv, por);
    }

}

void processCommand(char *commandNumber, char command, char *param1, char *param2, tList *list, int *votonull) {

    printf("********************\n");
    switch (command) {
        case 'N':
            printf("%s %c: participant %s location %s\n",commandNumber, command, param1, param2);
            new(param1, param2, list);
            break;
        case 'V':
            printf("%s %c: participant %s\n",commandNumber, command, param1);
            vote(param1,  list, votonull);
            break;
        case 'D':
            printf("%s %c: participant %s\n",commandNumber, command, param1);
            disqualify(param1,list, votonull);
            break;
        case 'S':
            printf("%s %c: totalvoters %s \n", commandNumber, command, param1);
            stats(param1,*list, *votonull);
            break;
        default:
            break;
    }
}

void readTasks(char *filename, int *votonull) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    //Crear lista
    tList list;
    createEmptyList(&list);

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, &list, votonull);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {
    int votonull=0;
    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name, &votonull);

    return 0;
}
