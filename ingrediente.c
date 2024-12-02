#include "ingrediente.h"

void adicionar_ingrediente_CRUD(){
    
}
void visualizar_ingrediente_CRUD(){}
void editar_ingrediente_CRUD(){}
void remover_ingrediente_CRUD(){}

int menu_ingrediente() {
    int NumeroOperaçãoingrediente=0;
    printf("\n");
    printf("*******************************|\n");
    printf("INGREDIENTE(s):                |\n");
    printf("*******************************|\n");
    printf(" 1 - Adicionar Ingrediente(s)  |\n");
    printf(" 2 - Visualizar Ingrediente(s) |\n");
    printf(" 3 - Editar Ingrediente(s)     |\n");
    printf(" 4 - Remover Ingrediente(s)    |\n");
    printf("*******************************|\n");
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
