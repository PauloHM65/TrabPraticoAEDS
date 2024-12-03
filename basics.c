#include "pizza.h"
#include "ingrediente.h"
#include "basics.h"

//vender pizza
int menu_venda(){}
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
void CRUD_PIZZA() {
    int respPizza =0;
    do {
        respPizza =menu_pizza();
    }while(respPizza==0);
}
void CRUD_INGREDIENTE(int *qtd) {
    int respIngrediente =0;
    do {
        respIngrediente = menu_ingrediente();
        switch(respIngrediente) {
            case 1:
                 adicionar_ingrediente_CRUD(qtd);
            break;
            case 2:
                visualizar_ingrediente_CRUD();
            break;
            case 3:
                editar_ingrediente_CRUD(qtd);
            break;
            case 4:
                remover_ingrediente_CRUD(qtd);
            break;
            case 0:
                printf(" --> CRUD_INGREDIENTE encerrando!!<--\n");
            break;
            default:
                printf("Opcao invalida!! Tente novamente");
        }
    }while(respIngrediente != 0);

}
void VENDA() {
    int respVenda =0;
    do {
        respVenda = menu_venda();
    }while(respVenda==0);
}