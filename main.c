#include "basics.h"

int carrega_quantidade_de_ingredientes() {
    int contadorLinhas = 0;
    char linha[100];
    FILE *arquivo;

    arquivo = fopen("Ingredientes.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo de carrega_quantidade_de_ingredientes");
        return 1;
    }

    while(fgets(linha, 100, arquivo) != NULL){
        contadorLinhas++;
    }

    fclose(arquivo);

    return contadorLinhas;
}

int main(void) {
    int respFinal=0, respMenuPrincipal=0, qtdIngrediente=0;
    qtdIngrediente = carrega_quantidade_de_ingredientes();
    printf("%d",qtdIngrediente);
    //mostra menu principal e chama o opção selecionada
    respFinal = menu_principal();
    if(respFinal == 4) {
        printf("!!!Programa se encerrando!!!\n");
    }
    while(respFinal != 4) {

            switch(respFinal) {

                case 1:
                    CRUD_PIZZA();
                break;
                case 2:
                    CRUD_INGREDIENTE(&qtdIngrediente);
                break;
                case 3:
                    VENDA();
                break;
                default:
                    printf("!!-->Opcao invalida<--!!\n");
                break;
            }
            respFinal = menu_principal();
            if(respFinal == 4) {
                printf("!!!Programa se encerrando!!!\n");
            }
    }

    return 0;
}