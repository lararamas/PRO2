/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: LARA RAMAS MARIÑO          LOGIN 1: lara.ramas
 * AUTHOR 2: ÁNGELA CLEMENTE LÓPEZ      LOGIN 2: angela.clemente
 * GROUP: 3.2
 * DATE: 04 / 03 / 2022
 */


#include "dynamic_list.h"

void createEmptyList(tList *L){
    *L = LNULL;
}

bool isEmptyList(tList L){
    return(L==LNULL);
}

tPosL first(tList L){
    return L;
}

tPosL last(tList L){
    tPosL p;
    for(p=L; p->next!=LNULL; p=p->next);
    return p;
}

tPosL next(tPosL p, tList L){ //tPosL next(tPosL p, tList L)
    return p->next;
}

tPosL previous (tPosL p, tList L){
    tPosL q;
    if(p==L) return LNULL;
    else{
        for(q=L; q->next!=p; q=q->next);
        return q;
    }
}

bool createNode(tPosL* p){
    *p=malloc(sizeof(**p));
    return *p != LNULL;
}

bool insertItem(tItemL d, tPosL p, tList *L) {
    tPosL q, r;
    if (!createNode(&q)) return false;
    else {
        q->data = d;
        q->next = LNULL;
        if (*L == LNULL) *L = q; //lista vacía
        else {
            q->data = d;
            q->next = LNULL;
            if (p == LNULL) { //último elemento
                for (r = *L; r->next != LNULL; r = r->next);
                r->next = q;
            } else if (p == *L) {
                q->next = *L;
                *L = q;
            } else {
                q->data = p->data;
                p->data = d;
                q->next = p->next;
                p->next = q;

            }
            return true;
        }
    }
}

void deleteAtPosition(tPosL p, tList *L){
    tPosL q; //para recorrer la lista
    if(p==*L){ //principio
        *L=(*L)->next;
    }else {
        if(p->next==LNULL){//final
            for(q=*L; q->next!=p; q=q->next);
            q->next=LNULL;
        }
        else{
            q = p->next;
            p->data = q->data;
            p->next = q->next;
            p = q;
        }
        free(p);
    }
}

tItemL getItem(tPosL p, tList L){ //tItemL getItem(tPosL p, tList L)
    return p->data;
}

void updateItem(tItemL d, tPosL p, tList *L){ //void updateItem(tItemL d, tPosL p, tList* L)
    p->data = d;
}


tPosL findItem (tParticipantName d, tList L){
    tPosL p;
    for (p=L; (p != LNULL) && (strcmp(p->data.participantName, d)!=0); p=p->next);
    return p;
}

void deleteList (tList *L){
    tPosL p;
    while(*L!=LNULL){
        p=*L;
        *L = (*L)->next;
        free(p);
    }
}