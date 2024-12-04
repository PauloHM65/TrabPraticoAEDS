#ifndef VENDA_H
#define VENDA_H
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "pizza.h"



//vender pizza


int menu_venda();
Pizza* venda_pizza_cardapio(int*);
Pizza* venda_pizza_adiciona_ingrediente(Pizza*,int*);
void venda_pizza(Pizza*,int*);
/*O preço final da pizza deve incluir o valor base mais o custo de
qualquer ingrediente extra.*/

Pizza* criaPizzaVenda();
#endif //VENDA_H
