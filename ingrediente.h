
#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


typedef struct Ingrediente {
    int id;
    char nome[20];
    float preco;
}Ingrediente;

Ingrediente* adicionar_ingrediente_CRUD(int *qnt);
void visualizar_ingrediente_CRUD();
void atualizar_ingredientes(Ingrediente *ingrediente, int qnt);
void editar_ingrediente_CRUD();
void remover_ingrediente_CRUD();

void CRUD_INGREDIENTE();



#endif //INGREDIENTE_H
