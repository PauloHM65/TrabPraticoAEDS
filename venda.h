#ifndef VENDA_H
#define VENDA_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "pizza.h"

#define TAMANHO_PIZZA_PEQUENA 40.00
#define TAMANHO_PIZZA_MEDIA 50.00
#define TAMANHO_PIZZA_GRANDE 60.00

//vender pizza


int menu_venda(Pizza*pizza);
Pizza* venda_pizza_cardapio(int*);
void venda_pizza_adiciona_ingrediente(Pizza*,int* );
void venda_pizza(Pizza*,int*);
/*O preço final da pizza deve incluir o valor base mais o custo de
qualquer ingrediente extra.*/
void visualiza_pizza_venda(Pizza*,int );
Pizza* criaPizzaVenda();
#endif //VENDA_H
