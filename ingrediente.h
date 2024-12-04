
#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define MAX_LENGTH_NAME_INGREDIENTE 30

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


typedef struct Ingrediente {
    int id;
    char nome[MAX_LENGTH_NAME_INGREDIENTE];
    float preco;
}Ingrediente;

void adicionar_ingrediente_CRUD(int* );
void visualizar_ingrediente_CRUD();
void atualizar_ingrediente(Ingrediente *, int );
void editar_ingrediente_CRUD(int* );
void remover_ingrediente_CRUD(int *);
int menu_ingrediente();

void CRUD_INGREDIENTE();



#endif //INGREDIENTE_H