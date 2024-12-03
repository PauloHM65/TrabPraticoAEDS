
#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


typedef struct Ingrediente {
    int id;
    char nome[30];
    float preco;
}Ingredientes;

void adicionar_ingrediente_CRUD(int *qnt);
void visualizar_ingrediente_CRUD();
void editar_ingrediente_CRUD();
void remover_ingrediente_CRUD();
int menu_ingrediente();

void CRUD_INGREDIENTE();



#endif //INGREDIENTE_H