
#ifndef PIZZA_H
#define PIZZA_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "ingrediente.h"

typedef struct Pizza{
    int Id;
    char Nome[30];
    char Tamanho;//P,M,G
    float Preco;
    Ingrediente Ingredientes[15];//Array com os ingredientes padrão da pizza
}Pizza;

void adicionar_pizza_CRUD();
void visualizar_pizza_CRUD();
void editar_pizza_CRUD();
void remover_pizza_CRUD();


int menu_pizza();



#endif //PIZZA_H
