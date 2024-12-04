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


int menu_venda();
Pizza* venda_pizza_cardapio();
void venda_pizza_adiciona_ingrediente(Pizza*pizza);
void venda_pizza(Pizza*pizza);
/*O preço final da pizza deve incluir o valor base mais o custo de
qualquer ingrediente extra.*/

Pizza* criaPizzaVenda();
#endif //VENDA_H
