#include "pizza.h"


void adicionar_pizza_CRUD(int *qnt_pizza)
{
    Pizza *pizza = (Pizza *)malloc(sizeof(Pizza));
    char continuar;

    do
    {
        printf("Digite o ID da Pizza: ");
        scanf("%d", &pizza->Id);
        getchar();

        printf("Digite o Nome da Pizza: ");
        fgets(pizza->Nome, 30, stdin);
        pizza->Nome[strcspn(pizza->Nome, "\n")] = '\0';

        printf("Digite o Tamanho da Pizza (P, M ou G): ");
        scanf(" %c", &pizza->Tamanho);
        pizza->Tamanho = toupper(pizza->Tamanho);
        getchar();

        if(pizza->Tamanho == 'P')
            pizza->Preco = TAMANHO_PIZZA_PEQUENA;
        if(pizza->Tamanho == 'M')
            pizza->Preco = TAMANHO_PIZZA_MEDIA;
        if(pizza->Tamanho == 'G')
            pizza->Preco = TAMANHO_PIZZA_GRANDE;


        // Abrir o arquivo de ingredientes
        FILE *arquivo_ingredientes = fopen("Ingredientes.txt", "r");

        if (arquivo_ingredientes == NULL)
        {
            printf("Erro ao abrir o arquivo de ingredientes. Certifique-se de que 'Ingredientes.txt' existe.\n");
            break;
        }

        printf("\nEscolha os ingredientes para a pizza:\n");

        // Mostrar ingredientes disponíveis
        char linha[100];
        int existe_ingrediente = 0;

        while (fgets(linha, sizeof(linha), arquivo_ingredientes))
        {
            int id = 0;
            char nome[30];
            float preco = 0.0;

            if (sscanf(linha, "%d;%29[^;];%f", &id, nome, &preco) == 3)
            {
                printf("%d - %s (R$ %.2f)\n", id, nome, preco);
                existe_ingrediente = 1;
            }
        }

        if (!existe_ingrediente)
        {
            printf("Nenhum ingrediente encontrado no arquivo!\n");
            fclose(arquivo_ingredientes);
            break;
        }
        fclose(arquivo_ingredientes);

        // Seleção de ingredientes
        int qnt_ingredientes = 0;
        while (qnt_ingredientes < 12)
        {
            int id_ingrediente;
            printf("Digite o ID do ingrediente (0 para finalizar): ");
            scanf("%d", &id_ingrediente);
            getchar();

            if (id_ingrediente == 0)
                break;

            // Reabrir o arquivo de ingredientes para buscar pelo ID
            arquivo_ingredientes = fopen("Ingredientes.txt", "r");
            if (arquivo_ingredientes == NULL)
            {
                printf("Erro ao abrir o arquivo de ingredientes.\n");
                break;
            }

            int encontrado = 0;
            while (fgets(linha, sizeof(linha), arquivo_ingredientes))
            {
                Ingrediente temp_ingrediente;
                if (sscanf(linha, "%d;%29[^;];%f", &temp_ingrediente.id, temp_ingrediente.nome, &temp_ingrediente.preco) == 3)
                {
                    if (temp_ingrediente.id == id_ingrediente)
                    {
                        pizza->Ingredientes[qnt_ingredientes] = temp_ingrediente;
                        qnt_ingredientes++;
                        encontrado = 1;
                        break;
                    }
                }
            }
            fclose(arquivo_ingredientes);

            if (!encontrado)
            {
                printf("Ingrediente com ID %d nao encontrado.\n", id_ingrediente);
            }
        }

        FILE *arquivo_pizzas = fopen("Pizzas.txt", "a");

        if (arquivo_pizzas == NULL)
        {
            printf("Erro ao abrir o arquivo de pizzas.\n");
            free(pizza);
            return;
        }
        // Salvar a pizza no arquivo de pizzas
        fprintf(arquivo_pizzas, "%d;%s;%c;%.2f;", pizza->Id, pizza->Nome, pizza->Tamanho, pizza->Preco);

        for (int i = 0; i < qnt_ingredientes; i++)
        {
            fprintf(arquivo_pizzas, "%d", pizza->Ingredientes[i].id);
            if (i < qnt_ingredientes - 1)
                fprintf(arquivo_pizzas, ",");
        }
        fprintf(arquivo_pizzas, "\n");

        (*qnt_pizza)++;

        printf("Gostaria de adicionar mais uma Pizza? (S/N): ");
        scanf(" %c", &continuar);
        getchar();

        fclose(arquivo_pizzas);
    } while (continuar == 'S' || continuar == 's');

    free(pizza);
}

void visualizar_pizza_CRUD()
{
    FILE *arquivo = fopen("Pizzas.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    char linha[200];
    printf("\nCardapio de Pizzas:\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        int id;
        char nome[30], tamanho;
        float preco;
        char ingredientes_ids[100];

        // Lê os dados da pizza, incluindo os IDs dos ingredientes
        if (sscanf(linha, "%d;%29[^;];%c;%f;%99[^\n]", &id, nome, &tamanho, &preco, ingredientes_ids) == 5)
        {
            printf("%d - %s (%c) R$%.2f\n", id, nome, tamanho, preco);
            printf("  Ingredientes: ");

            // Exibe os ingredientes
            char *token = strtok(ingredientes_ids, ",");
            while (token)
            {
                int id_ingrediente = atoi(token);

                // Carrega o ingrediente do arquivo de ingredientes
                FILE *arquivo_ingredientes = fopen("Ingredientes.txt", "r");
                if (arquivo_ingredientes == NULL)
                {
                    printf("\nErro ao abrir o arquivo de ingredientes.\n");
                    break;
                }

                char linha_ingrediente[100];
                while (fgets(linha_ingrediente, sizeof(linha_ingrediente), arquivo_ingredientes))
                {
                    Ingrediente temp_ingrediente;
                    if (sscanf(linha_ingrediente, "%d;%29[^;];%f", &temp_ingrediente.id, temp_ingrediente.nome, &temp_ingrediente.preco) == 3)
                    {
                        if (temp_ingrediente.id == id_ingrediente)
                        {
                            printf("%s (R$%.2f), ", temp_ingrediente.nome, temp_ingrediente.preco);
                            break;
                        }
                    }
                }
                fclose(arquivo_ingredientes);

                token = strtok(NULL, ",");
            }
            printf("\n");
        }
    }

    fclose(arquivo);
}
void editar_pizza_CRUD(){}
void remover_pizza_CRUD(){}


int menu_pizza() {
    int NumeroOperacaoPizza=0;
    printf("\n");
    printf("*****************************|\n");
    printf("PIZZA(s):                    |\n");
    printf("*****************************|\n");
    printf(" 1 - Adicionar Pizza         |\n");
    printf(" 2 - Visualizar Pizzas       |\n");
    printf(" 3 - Editar Pizza            |\n");
    printf(" 4 - Remover Pizza           |\n");
    printf(" 0 - Encerrar PIZZA(s)       |\n");
    printf("*****************************|\n");
    scanf("%d",&NumeroOperacaoPizza);

    return NumeroOperacaoPizza;
}





