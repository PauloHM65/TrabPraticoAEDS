#include "pizza.h"

//crud pizza
void adicionar_pizza_CRUD(){}
void visualizar_pizza_CRUD(){}
void editar_pizza_CRUD(){}
void remover_pizza_CRUD(){}


int menu_pizza() {
    int NumeroOperaçãoPizza=0;
    printf("\n");
    printf("*****************************|\n");
    printf("PIZZA(s):                    |\n");
    printf("*****************************|\n");
    printf(" 1 - Adicionar Pizza         |\n");
    printf(" 2 - Visualizar Pizzas       |\n");
    printf(" 3 - Editar Pizza            |\n");
    printf(" 4 - Remover Pizza           |\n");
    printf("*****************************|\n");
    scanf("%d",&NumeroOperaçãoPizza);
    if (!(NumeroOperaçãoPizza == 1 || NumeroOperaçãoPizza == 2 || NumeroOperaçãoPizza == 3|| NumeroOperaçãoPizza == 4)) {
        NumeroOperaçãoPizza = 0;
    }
    return NumeroOperaçãoPizza;
}





