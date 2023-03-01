/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: LARA RAMAS MARIÑO          LOGIN 1: lara.ramas
 * AUTHOR 2: ÁNGELA CLEMENTE LÓPEZ      LOGIN 2: angela.clemente
 * GROUP: 3.2
 * DATE: 04 / 03 / 2022
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define LNULL NULL


typedef struct tNode *tPosL;
struct  tNode {
    struct tItemL data;
    tPosL next;
};

typedef tPosL tList;

void createEmptyList(tList *L);
bool isEmptyList (tList L);
tPosL first (tList L);
tPosL last (tList L);
tPosL next (tPosL p, tList L);
tPosL previous (tPosL p, tList L);
bool insertItem (tItemL d , tPosL p, tList *L);
void deleteAtPosition (tPosL p, tList *L);
tItemL getItem (tPosL p, tList L);
void updateItem (tItemL d, tPosL p, tList *L);
tPosL  findItem (tParticipantName d, tList L);
void deleteList (tList *L);


#endif
