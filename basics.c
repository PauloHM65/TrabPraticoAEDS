#include "headers/pizza.h"
#include "headers/ingrediente.h"
#include "headers/venda.h"
#include "headers/basics.h"


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
// so adicionei o while e a tela

void CRUD_PIZZA() {
    int respPizza =0;
    do {
        respPizza = menu_pizza();
        switch(respPizza) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 0:
                printf(" --> CRUD_PIZZA encerrando!!<--\n");
            break;
            default:
                printf("Opcao invalida!! Tente novamente");
        }
    }while(respPizza != 0);
}
// 03/12 - Falta arruma o remover
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
// so adicionei o while e a tela
void VENDA() {
    int respVenda =0;
    do {
        respVenda = menu_venda();
        switch(respVenda) {
            case 1:
                venda_pizza();
            break;
            case 2:
                venda_pizza_cardapio();
            break;
            case 3:
                venda_pizza_adiciona_ingrediente();
            break;
            case 0:
                printf(" --> VENDA encerrando!!<--\n");
            break;
            default:
                printf("Opcao invalida!! Tente novamente");
        }
    }while(respVenda != 0);
}