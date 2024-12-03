
#ifndef PIZZA_H
#define PIZZA_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct pizza{
    int Id;
    char Nome[30];
    char Tamanho;//P,M,G
    float Preco;
    char Ingredientes[50];//Array com os ingredientes padrão da pizza
}pizza;

void adicionar_pizza_CRUD();
void visualizar_pizza_CRUD();
void editar_pizza_CRUD();
void remover_pizza_CRUD();


int menu_pizza();



#endif //PIZZA_H