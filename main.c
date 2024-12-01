#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funçoes
//crud pizza

void adicionar_pizza_CRUD(){}
void visualizar_pizza_CRUD(){}
void editar_pizza_CRUD(){}
void remover_pizza_CRUD(){}

//crud ingrediente

void adicionar_ingrediente_CRUD(){}
void visualizar_ingrediente_CRUD(){}
void editar_ingrediente_CRUD(){}
void remover_ingrediente_CRUD(){}

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






typedef struct Ingrediente {
    int Id;
    char Nome[20];
    float Preço;
}Ingrediente;

typedef struct pizza{
    int Id;
    char Nome[30];
    char Tamanho;//P,M,G
    float Preco;
    Ingrediente Ingredientes[];//Array com os ingredientes padrão da pizza
}pizza;

int menu_principal() {
    int NumeroOperação=0;
    printf("-----------------------------\n");
    printf("Digite a numero da operacao:\n");
    printf("-----------------------------\n");
    printf(" 1 - Pizza\n");
    printf(" 2 - Ingredientes\n");
    printf("-----------------------------\n");
    printf(" 3 - Realizar uma venda\n");
    printf("-----------------------------\n");
    printf("-----------------------------\n");
    printf(" 4 - Encerrar o programa\n");
    printf("-----------------------------\n");
    scanf("%d",&NumeroOperação);
    if (!(NumeroOperação == 1 || NumeroOperação == 2 || NumeroOperação == 3|| NumeroOperação == 4)) {
        NumeroOperação = 0;
    }
    return NumeroOperação;
}
int main() {
    int respFinal=0;

    int respMenuPrincipal=0;

    //mostra menu principal e chama o opção selecionada
    respFinal = menu_principal();
    if(respFinal == 4) {
        printf("!!Programa se encerrando!!\n");
    }
    while(respFinal != 4) {
            switch(respFinal) {
                case 1:
                    printf("PIZZAs:\n");
                break;
                case 2:
                    printf("INGREDIENTEs:\n");
                break;
                case 3:
                    printf("VENDA:\n");
                break;
                case (4):
                    printf("!!Programa se encerrando!!\n");
                break;
                default:
                    printf("Opcao invalida!!\n");
                break;
            }
        }
        respFinal = menu_principal();
    }


    return 0;
}