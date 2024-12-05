
#ifndef PIZZA_H
#define PIZZA_H

#define TAMANHO_PIZZA_PEQUENA 40.00
#define TAMANHO_PIZZA_MEDIA 50.00
#define TAMANHO_PIZZA_GRANDE 60.00

#define MAX_INGREDIENTE 12
#define MAX_LENGTH_NAME_PIZZA 30


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "ingrediente.h"

typedef struct Pizza{
    int Id;
    char Nome[MAX_LENGTH_NAME_PIZZA];
    char Tamanho;//P,M,G
    float Preco;
    Ingrediente Ingredientes[MAX_INGREDIENTE];//Array com os ingredientes padrão da pizza
}Pizza;
typedef struct Pizza2 {
    int Id;
    char Nome[30];
    char Tamanho;//P,M,G
    float Preco;
    char Ingredientes[30];
}Pizza2;
void adicionar_pizza_CRUD();
void atualiza_pizza(Pizza2*,int*);
void visualizar_pizza_CRUD();
void editar_pizza_CRUD();
void remover_pizza_CRUD(int*);

int pegaTamanhoArquivoPizza();

int menu_pizza();



#endif //PIZZA_H
