/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: LARA RAMAS MARIÑO          LOGIN 1: lara.ramas
 * AUTHOR 2: ÁNGELA CLEMENTE LÓPEZ      LOGIN 2: angela.clemente
 * GROUP: 3.2
 * DATE: 04 / 03 / 2022
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define LNULL -1
#define MAX 25

typedef int tPosL;

typedef struct {
    tItemL data [MAX];
    tPosL lastPos;

} tList;

void createEmptyList(tList *L);
/*Crea una lista vacía
 *Entrada: lista a inicializar
 *Salida: lista inicializada
 *Poscondición: La lista queda iniciada y no contiene elementos.
 */
bool isEmptyList(tList L);
/*Determina si la lista está vacía.
 *Entrada: lista a comprobar
 *Salida: booleano con el resultado de la comprobación
 */

tPosL first (tList L);
/*Devuelve la posición del primer elemento de la lista
 *Entrada: lista a porcesar
 *Salida: Posición del primer elemento de la lista
 *Precondición: La lista no está vacía
 */
tPosL last (tList L);
/*Devuelve la posición del último elemento de la lista
 *Entrada: lista a porcesar
 *Salida: Posición del primer último de la lista
 *Precondición: La lista no está vacía
 */
tPosL next (tPosL p, tList L);
/*Devuelve la posición en la lista del elemento siguiente al de la posición indicada (o LNULL si la posición no tiene siguiente).
 *Entrada: lista a porcesar
 *         posición del elemento previo al que se quiere
 *Salida: Posición del siguiente elemento al indicado en la lista
 *Precondición: La posición indicada es una posición válida en la lista
 */
tPosL previous (tPosL p, tList L);
/*Devuelve la posición en la lista del elemento previo al de la posición indicada (o LNULL si la posición no tiene anterior).
 *Entrada: lista a porcesar
 *         posición del elemento siguiente al que se quiere
 *Salida: Posición del previo elemento al indicado en la lista
 *Precondición: La posición indicada es una posición válida en la lista
 */
bool insertItem (tItemL d , tPosL p, tList *L);
/*Inserta un elemento en la lista antes de la posición indicada.
  Si la posición es LNULL, entonces se añade al final. Devuelve un valor true si el elemento fue insertado; false en caso contrario.
 *Entrada: lista a porcesar
 *         posición del elemento a insertar o LNULL
 *         nuevo elemento a insertar
 *Salida: verificación de que la inserción funcionara
 *Precondición: La posición indicada es una posición válida en la lista o bien nula (LNULL).
 *Poscondición: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haver variado.
 */
void deleteAtPosition (tPosL p, tList *L);
/*Elimina de la lista el elemento que ocupa la posición indicada.
 *Entrada: lista a porcesar
 *         posición del elemento a eliminar
 *Salida: lista modificada
 *Precondición: La posición indicada es una posición válida en la lista.
 *Poscondición: Las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado
 */
tItemL getItem (tPosL p, tList L);
/*Devuelve el contenido del elemento de la lista que ocupa la posición indicada.
 *Entrada: lista a porcesar
 *         posición del elemento a obtener
 *Salida: elemento en la posición dada
 *Precondición: La posición indicada es una posición válida en la lista.
 */
void updateItem (tItemL d, tPosL p, tList *L);
/*Modifica el contenido del elemento situado en la posición indicada.
 *Entrada: lista a porcesar
 *         posición del elemento a actualizar
 *         nuevo elemento
 *Salida: lista actualizada
 *Precondición: La posición indicada es una posición válida en la lista.
 *Poscondición: El orden de los elementos de la lista no se ve modificado.
 */
tPosL  findItem (tParticipantName d, tList L);
/*Devuelve la posición del primer elemento de la lista cuyo nombre de participante se corresponda con el indicado
  (o LNULL si no existe tal elemento)
 *Entrada: lista a porcesar
 *         nombre a buscar
 *Salida: posición del elemento que coincide con el nombre
 */



#endif

