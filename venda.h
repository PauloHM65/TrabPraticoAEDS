#ifndef VENDA_H
#define VENDA_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "pizza.h"

#define pizza_pequena 40.00
#define pizza_media 50.00
#define pizza_grande 60.00

//vender pizza


int menu_venda();
Pizza* venda_pizza_cardapio();
Pizza* venda_pizza_adiciona_ingrediente();
void venda_pizza();
/*O preço final da pizza deve incluir o valor base mais o custo de
qualquer ingrediente extra.*/

Pizza* criaPizzaVenda();
#endif //VENDA_H
