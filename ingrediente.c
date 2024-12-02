#include "ingrediente.h"

Ingredientes* adicionar_ingrediente_CRUD(){
    Ingredientes *ingrediente;
    int qnt = 0;//Contador para a quantidade de ingredientes que serao cadastrados
    char continuar;

    do{
        ingrediente = realloc(ingrediente, (qnt + 1) * sizeof(Ingredientes));
        
        printf("Digite o ID do Ingrediente: ");
        scanf("%d", &ingrediente[qnt].id);
        getchar();
        printf("\n");
        
        printf("Digite o nome do Ingrediente: ");
        fgets(ingrediente[qnt].nome, 30, stdin);
        ingrediente[qnt].nome[strcspn(ingrediente[qnt].nome, "\n")] = '\0';
        printf("\n");
        
        printf("Digite o preço do Ingrediente: ");
        scanf("%f", &ingrediente[qnt].preco);

        qnt++;

        printf("Gostaria de adicionar mais um Ingrediente? ");
        scanf(" %c", &continuar);        
    }while(continuar == 'S' || continuar == 's'); 

    return ingredientes;
}
int quantidade_ingredientes_cadastrados(){
    int quantidade = 0;
    char linha[30];
    
    FILE* arquivo = fopen("ingredientes.txt", "r");
    
    while (fgets(Linha, sizeof(Linha), arquivo) != NULL)
    {
        quantidade++;
    }
return quantidade;
}
void visualizar_ingrediente_CRUD(int qnt){
    int qnt = quantidade_ingredientes_cadastrados();
    printf("\nIngredientes cadastrados:\n");
    for(int i = 0; i < qnt; i++){
        printf("%d - %s R$%.2f\n", ingrediente[i].id, ingrediente[i].nome, ingrediente[i].preco);
    }
}
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
