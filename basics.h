#ifndef BASICS_H
#define BASICS_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "pizza.h"
#include "ingrediente.h"
#include "venda.h"


void salvar_cardapio_pizza();
void salvar_cardapio_ingedientes();

void ler_cardapio_pizza();
void ler_cardapio_ingedientes();




int menu_principal();
void CRUD_PIZZA();
void CRUD_INGREDIENTE();
void VENDA();



#endif //BASICS_H
