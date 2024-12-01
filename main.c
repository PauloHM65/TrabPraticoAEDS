#include "pizza.h">
#include "ingrediente.h"
#include "basics.h"



int main(void) {
    int respFinal=0;

    int respMenuPrincipal=0;

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
                    CRUD_INGREDIENTE();
                break;
                case 3:
                    VENDA();
                break;
                case (4):
                    printf("!!Programa se encerrando!!\n");
                break;
                default:
                    printf("Opcao invalida!!\n");
                break;
            }
            respFinal = menu_principal();
        }



    return 0;
}