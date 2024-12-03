//
// Created by paulo on 03/12/2024.
//

#include "headers/venda.h"



//vender pizza

void venda_pizza(){}
void venda_pizza_cardapio(){}
void venda_pizza_adiciona_ingrediente(){}
/*O preço final da pizza deve incluir o valor base mais o custo de
qualquer ingrediente extra.*/

int menu_venda() {
    int NumeroOperaçãoVenda = 0;
    printf("\n");
    printf("************************************|\n");
    printf("VENDA(s):                           |\n");
    printf("************************************|\n");
    printf(" 1 - Selecionar pizza do cardapio   |\n");
    printf(" 2 - Adicionar mais ingradiente(s)  |\n");
    printf(" 3 - Ralizar a conta e vender       |\n");
    printf(" 0 - Fechar VENDA(s)                |\n");
    printf("************************************|\n");
    scanf("%d",&NumeroOperaçãoVenda);

    return NumeroOperaçãoVenda;

}