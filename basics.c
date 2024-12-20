#include "basics.h"





int menu_principal() {
    int NumeroOperacao=0;
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
    scanf("%d",&NumeroOperacao);
    if (!(NumeroOperacao == 1 || NumeroOperacao == 2 || NumeroOperacao == 3|| NumeroOperacao == 4)) {
        NumeroOperacao = 0;
    }
    return NumeroOperacao;
}

void CRUD_PIZZA(int *qtdPIZZA) {
    int respPizza =0;
    do {
        respPizza = menu_pizza();
        switch(respPizza) {
            case 1:
                adicionar_pizza_CRUD(qtdPIZZA);
                break;
            case 2:
                visualizar_pizza_CRUD();
                break;
            case 3:
                editar_pizza_CRUD(qtdPIZZA);
                break;
            case 4:
                remover_pizza_CRUD(qtdPIZZA);
                break;
            case 0:
                printf(" --> CRUD_PIZZA encerrando!!<--\n");
            break;
            default:
                printf("Opcao invalida!! Tente novamente");
        }
    }while(respPizza != 0);
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
                printf("%d",*qtd);
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
    Pizza* pizza = criaPizzaVenda();
    int qtd=0;

    int respVenda =0;
    do {
        respVenda = menu_venda(pizza);
        switch(respVenda) {
            case 1:
                // pizza do cardapio
                    pizza = venda_pizza_cardapio(&qtd);
            break;
            case 2:
                //adicionar mais ingredientes
                    venda_pizza_adiciona_ingrediente(pizza,&qtd);
            break;
            case 3:
                //fazer a venda
                    venda_pizza(pizza,&qtd);
            break;
            case 0:
                printf(" --> VENDA encerrando!!<--\n");
            break;
            default:
                printf("Opcao invalida!! Tente novamente");
        }

    }while(respVenda != 0);
    free(pizza);
}