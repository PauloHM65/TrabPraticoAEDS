#include "ingrediente.h"

void adicionar_ingrediente_CRUD(){}
void visualizar_ingrediente_CRUD(){}
void editar_ingrediente_CRUD(){}
void remover_ingrediente_CRUD(){}

int menu_ingrediente() {
    int NumeroOperaçãoingrediente=0;
    printf("\n");
    printf("*****************************|\n");
    printf("PIZZA(s):                    |\n");
    printf("*****************************|\n");
    printf(" 1 - Adicionar Pizza         |\n");
    printf(" 2 - Visualizar Pizzas       |\n");
    printf(" 3 - Editar Pizza            |\n");
    printf(" 4 - Remover Pizza           |\n");
    printf("*****************************|\n");
    scanf("%d",&NumeroOperaçãoingrediente);
    if (!(NumeroOperaçãoingrediente == 1 || NumeroOperaçãoingrediente == 2 || NumeroOperaçãoingrediente == 3|| NumeroOperaçãoingrediente == 4)) {
        NumeroOperaçãoingrediente = 0;
    }
    return NumeroOperaçãoingrediente;
}




void CRUD_INGREDIENTE() {
    int respOpcao=0;
    respOpcao = menu_ingrediente();
}