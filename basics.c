#include "basics.h"

//vender pizza

void venda_pizza(){}
void venda_pizza_cardapio(){}
void venda_pizza_adiciona_ingrediente(){}
/*O preço final da pizza deve incluir o valor base mais o custo de
qualquer ingrediente extra.*/


//Exportar e Importar Dados
//exportação
void salvar_cardapio_pizza(){}
void salvar_cardapio_ingedientes(){}
//importação
void ler_cardapio_pizza(){}
void ler_cardapio_ingedientes(){}

void VENDA() {
    printf("VENDA:\n");
}



int menu_principal() {
    int NumeroOperação=0;
    printf("\n");
    printf("*****************************|\n");
    printf("Digite a numero da operacao: |\n");
    printf("*****************************|\n");
    printf(" 1 - Pizza                   |\n");
    printf(" 2 - Ingredientes            |\n");
    printf("-----------------------------|\n");
    printf(" 3 - Realizar uma venda      |\n");
    printf("-----------------------------|\n");
    printf(" 4 - Encerrar o programa     |\n");
    printf("*****************************|\n");
    scanf("%d",&NumeroOperação);
    if (!(NumeroOperação == 1 || NumeroOperação == 2 || NumeroOperação == 3|| NumeroOperação == 4)) {
        NumeroOperação = 0;
    }
    return NumeroOperação;
}