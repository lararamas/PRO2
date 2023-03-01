/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: LARA RAMAS MARIÑO          LOGIN 1: lara.ramas
 * AUTHOR 2: ÁNGELA CLEMENTE LÓPEZ      LOGIN 2: angela.clemente
 * GROUP: 3.2
 * DATE: 04 / 03 / 2022
 */

#include "static_list.h"
#include "string.h"
#include "types.h"
#include <stdbool.h>

void createEmptyList(tList *L){
    L-> lastPos=LNULL;
}

bool isEmptyList (tList L){
    return (L.lastPos==LNULL);
}

tPosL first(tList L){
    return 0;
}

tPosL last(tList L){
    return L.lastPos;
}

tPosL previous (tPosL p, tList L){
    return --p;
}

tPosL next (tPosL p, tList L){
    if (p==L.lastPos)
        return LNULL;
    else
        return ++p;
}

bool insertItem (tItemL d , tPosL p, tList *L){
    tPosL i;
    if(L->lastPos == MAX-1)
        return false;
    else {
        L->lastPos++;
        if (p==LNULL)
            L->data[L->lastPos]=d;
        else{
            for (i =L->lastPos; i >= p+1; i--){
                L->data[i]= L->data[i-1];
            }
            L->data[p]=d;
        }
        return true;
    }

}
void deleteAtPosition (tPosL p, tList *L){
    int i;
    L->lastPos--;
    for(i=p; i<= L->lastPos;i++){
        L->data[i]= L->data[i+1];
    }

}


tItemL getItem(tPosL p, tList L){
    return L.data [p];
}

void updateItem (tItemL d, tPosL p, tList *L){
    L->data[p] = d;
}


tPosL  findItem (tParticipantName d, tList L) {
    tPosL p;
    if(L.lastPos == LNULL)
        return LNULL;
    else{
        for(p=0; (p<L.lastPos) && (strcmp(L.data [p].participantName,d)!= 0); p++);
        if(strcmp(L.data[p].participantName,d)==0)
            return p;
        else
            return LNULL;
    }
}
