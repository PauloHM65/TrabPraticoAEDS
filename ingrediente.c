#include "ingrediente.h"

void adicionar_ingrediente_CRUD(int *qnt)
{
    Ingrediente *ingrediente = (Ingrediente*)malloc( sizeof(Ingrediente));
    char continuar;
    FILE *arquivo = fopen("Ingredientes.txt", "a");

    do
    {


        printf("Digite o ID do Ingrediente: ");
        scanf("%d", &ingrediente[*qnt].id);
        getchar();

        printf("Digite o nome do Ingrediente: ");
        fgets(ingrediente[*qnt].nome, 30, stdin);
        ingrediente[*qnt].nome[strcspn(ingrediente[*qnt].nome, "\n")] = '\0';

        printf("Digite o preco do Ingrediente: ");
        scanf("%f", &ingrediente[*qnt].preco);getchar();

        fprintf(arquivo, "%d;%s;%.2f\n", ingrediente[*qnt].id, ingrediente[*qnt].nome, ingrediente[*qnt].preco);

        (*qnt)++;

        printf("Gostaria de adicionar mais um Ingrediente? (S / N)");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    free(ingrediente);
    fclose(arquivo);
}
void visualizar_ingrediente_CRUD()
{
    FILE *arquivo = fopen("Ingredientes.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
    }

    char linha[100];
    printf("\nIngrediente cadastrados no arquivo:\n");

    int existe_ingrediente = 0; // Flag para verificar se há ingrediente no arquivo
    while (fgets(linha, sizeof(linha), arquivo))
    {
        int id = 0;
        char nome[30];
        float preco = 0.0;

        // Lê os dados da linha no formato esperado
        // printf("%s\n", linha);
        if (sscanf(linha, "%d;%29[^;];%f", &id, nome, &preco) == 3)
        {
            printf("%d - %s R$%.2f\n", id, nome, preco);
            existe_ingrediente = 1; // Marca que encontrou pelo menos um ingrediente
        }
    }

    if (!existe_ingrediente)
    {
        printf("Nenhum ingrediente encontrado no arquivo!\n");
    }
    fclose(arquivo);
}

void atualizar_ingrediente(Ingrediente *ingrediente, int qnt)
{
    FILE *arquivo = fopen("Ingredientes.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar os ingrediente.\n");
        return;
    }

    for (int i = 0; i < qnt; i++)
    {
        fprintf(arquivo, "%d;%s;%.2f\n", ingrediente[i].id, ingrediente[i].nome, ingrediente[i].preco);
    }

    fclose(arquivo);
}

void editar_ingrediente_CRUD( int *qnt)
{
    char alteracao[10], novo_nome[30],nome[30],linha[100];
    int id_alteracao, posicao_alteracao=-1,id = 0;;
    float novo_preco = 0.0,preco = 0.0;
    FILE *arquivo = fopen("Ingredientes.txt", "r");
    Ingrediente* ingrediente =NULL;
    ingrediente = (Ingrediente*)realloc(ingrediente, (*qnt)*sizeof(Ingrediente));


    visualizar_ingrediente_CRUD();
    printf("Digite o ID do Ingrediente a ser alterado: \n");
    scanf("%d", &id_alteracao);
    getchar();

    for (int i =0 ; i < *qnt; i++)
    {
        fgets(linha, 100, arquivo);
        if (sscanf(linha, "%d;%29[^;];%f", &id, nome, &preco) == 3)
        {

            ingrediente[i].id = id;
            ingrediente[i].preco = preco;
            strcpy(ingrediente[i].nome,nome);
            if (ingrediente[i].id == id_alteracao)
            {
                posicao_alteracao = i;
            }
        }

    }

    if (posicao_alteracao < 0)
    {
        printf("Ingrediente com ID %d nao encontrado.\n", id_alteracao);
        return;
    }


        printf("O que gostaria de alterar(Nome ou Preco)?: \n");
        fgets(alteracao, 10, stdin);
        alteracao[strcspn(alteracao, "\n")] = '\0';

        if (strcmp(alteracao, "nome") == 0)
        {
            printf("Qual o novo nome?\n");
            fgets(novo_nome, 30, stdin);
            novo_nome[strcspn(novo_nome, "\n")] = '\0';
            strcpy(ingrediente[posicao_alteracao].nome, novo_nome);
        }
        else if (strcmp(alteracao, "preco") == 0)
        {
            printf("Qual o novo preco?\n");
            scanf("%f", &novo_preco);
            getchar();
            ingrediente[posicao_alteracao].preco = novo_preco;
        }    

    printf("%s - %f",ingrediente[posicao_alteracao].nome,ingrediente[posicao_alteracao].preco);

    atualizar_ingrediente(ingrediente, *qnt);
    free(ingrediente);
}

void remover_ingrediente_CRUD(int *qtd) {
    int tamanhoArquivo = *qtd, novaQtd = 0,i=0;
    char id_para_remover[3];
    Ingrediente *ingredientes = (Ingrediente *)calloc(tamanhoArquivo, sizeof(Ingrediente));

    if (ingredientes == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    FILE *arquivo = fopen("Ingredientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(ingredientes);
        return;
    }
    // Exibir os ingredientes
    visualizar_ingrediente_CRUD();
    printf("Digite o ID do item a ser removido:\n");getchar();
    fgets(id_para_remover, sizeof(id_para_remover), stdin);getchar();
    id_para_remover[strcspn(id_para_remover, "\n")] = '\0'; // Remover o '\n'

    while (i < tamanhoArquivo) {
        char linha[100];

        if (fgets(linha, sizeof(linha), arquivo) != NULL) {
            Ingrediente ingredienteTemporario;

            // Verifique se a linha está no formato esperado
            sscanf(linha, "%d;%29[^;];%f", &ingredienteTemporario.id, ingredienteTemporario.nome, &ingredienteTemporario.preco);
            char idStr[10];
            sprintf(idStr, "%d", ingredienteTemporario.id);

            // Comparar o ID lido com o ID para remover
            if (strcmp(idStr, id_para_remover) != 0) {
                // Se for diferente, mantemos no array
                ingredientes[novaQtd] = ingredienteTemporario;
                novaQtd++;

            }
            i++;
        } else {
            i++;
        }
    }

    fclose(arquivo);

    if (novaQtd == tamanhoArquivo) {
        printf("Nenhum ingrediente foi removido. ID nao encontrado.\n");
    } else {
        (*qtd) = novaQtd; // Atualiza a quantidade de ingredientes
        atualizar_ingrediente(ingredientes, *qtd);
        printf("Ingrediente removido com sucesso!\n");
    }

    free(ingredientes);
}

int menu_ingrediente() {
    int NumeroOperacaoingrediente = 0;
    printf("\n");
    printf("********************************|\n");
    printf("INGREDIENTE(s):                 |\n");
    printf("********************************|\n");
    printf(" 1 - Adicionar Ingrediente(s)   |\n");
    printf(" 2 - Visualizar Ingrediente(s)  |\n");
    printf(" 3 - Editar Ingrediente(s)      |\n");
    printf(" 4 - Remover Ingrediente(s)     |\n");
    printf(" 0 - Fechar CRUD_INGREDIENTE(s) |\n");
    printf("********************************|\n");
    scanf("%d",&NumeroOperacaoingrediente);

    return NumeroOperacaoingrediente;
}





