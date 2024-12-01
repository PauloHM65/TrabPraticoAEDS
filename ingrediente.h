
#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


typedef struct Ingrediente {
    int Id;
    char Nome[20];
    float Preço;
}Ingrediente;

void adicionar_ingrediente_CRUD();
void visualizar_ingrediente_CRUD();
void editar_ingrediente_CRUD();
void remover_ingrediente_CRUD();

void CRUD_INGREDIENTE();



#endif //INGREDIENTE_H