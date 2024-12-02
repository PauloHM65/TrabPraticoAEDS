#include "ingrediente.h"

Ingredientes* adicionar_ingrediente_CRUD(int *qnt){//qnt = quantidade de ingredientes, deve ser inicializado na main e na hora de chamar a funcao passar o seu endereco como parametro
    Ingredientes *ingrediente = NULL;
    char continuar;
    FILE* arquivo = fopen("Ingredientes.txt", "a");

    do{
        ingrediente = realloc(ingrediente, (*qnt + 1) * sizeof(Ingredientes));
        
        printf("Digite o ID do Ingrediente: ");
        scanf("%d", &ingrediente[*qnt].id);
        getchar();
        
        printf("Digite o nome do Ingrediente: ");
        fgets(ingrediente[*qnt].nome, 30, stdin);
        ingrediente[qnt].nome[strcspn(ingrediente[*qnt].nome, "\n")] = '\0';
        printf("\n");
        
        printf("Digite o preco do Ingrediente: ");
        scanf("%f", &ingrediente[*qnt].preco);

         fprintf(arquivo, "%d - %s R$%.2f\n", ingrediente[*qnt].id, ingrediente[*qnt].nome, ingrediente[*qnt].preco);
        
        (*qnt)++;

        printf("\n");
        printf("Gostaria de adicionar mais um Ingrediente?(S ou N) ");
        scanf(" %c", &continuar);        
    }while(continuar == 'S' || continuar == 's'); 

    fclose(arquivo);
    return ingredientes;
}
void visualizar_ingrediente_CRUD(Ingredientes *ingrediente, int qnt){//ingredientes deve ser 
    printf("\nIngredientes cadastrados:\n");
    for(int i = 0; i < qnt; i++){
        printf("%d - %s R$%.2f\n", ingrediente[i].id, ingrediente[i].nome, ingrediente[i].preco);
    }
}
void editar_ingrediente_CRUD(Ingredientes *ingrediente, int qnt){
    char alteracao[10], novo_nome[30];    
    int id_alteracao, posicao_alteracao;
    float novo_preco = 0.0;
    FILE* arquivo = fopen("Ingredientes.txt", "a");

    visualizar_ingrediente_CRUD(Ingredientes *ingrediente, int qnt);
    printf("Digite o ID do Ingrediente a ser alterado: \n");
    getchar();

    for(int i = 0; i < qnt; i++){
        if(ingrediente[i].id == id_alteracao){
            posicao_alteracao = i;
        }
    }
        
    printf("O que gostaria de alterar(Nome ou Preco)?: \n");
    fgets(alteracao, 10, stdin);
    alteracao[strcspn(alteracao, "\n")] = '\0';
        
    if(strcmp(alteracao, "nome") == 0){
    printf("Qual o novo nome?\n");
    fgets(novo_nome, 30, stdin);
    novo_nome[strcspn(novo_nome, "\n")] = '\0';
    strcpy(ingrediente[posicao_alteracao].nome, novo_nome);
    }else if(strcmp(alteracao, "preco") == 0){
    printf("Qual o novo preco?\n");
    scanf("%f", &novo_preco);
    getchar();
    ingrediente[posicao_alteracao].preco = novo_preco;
    }
        
}
void remover_ingrediente_CRUD(){}

int menu_ingrediente() {
    int NumeroOperaçãoingrediente = 0;
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
