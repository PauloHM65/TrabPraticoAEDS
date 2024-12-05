#include "pizza.h"

/*int pegaTamanhoArquivoPizza() {
    int contadorLinhas = 0;
    char linha[100];
    FILE *arquivo = fopen("Pizzas.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo para contar tamanho pizzas");
        return 1;
    }

    while(fgets(linha, 100, arquivo) != NULL){
        contadorLinhas++;
    }

    fclose(arquivo);

    return contadorLinhas;
} */

void atualiza_pizza(Pizza2* pizza, int *qtd) {
    FILE *arquivo = fopen("Pizzas.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar os pizza.\n");
    }

    for (int i = 0; i < *qtd; i++)
    {
        fprintf(arquivo, "%d;%s;%c;%.2f;%s\n", pizza[i].Id, pizza[i].Nome,
            pizza[i].Tamanho, pizza[i].Preco,pizza[i].Ingredientes);
    }

    fclose(arquivo);
}
Pizza* pegaNomeEPrecoToken(const int Id) {
    Pizza *pizza = (Pizza*)malloc(sizeof(Pizza));
    if (pizza == NULL) {
        perror("Erro ao alocar memória para Pizza");
        return NULL;
    }

    FILE* file = fopen("Ingredientes.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo Ingredientes.txt");
        free(pizza);
        return NULL;
    }

    char linha[200];
    pizza->Nome[0] = '\0'; // Inicializa com string vazia
    pizza->Preco = 0.0;   // Inicializa com 0

    while (fgets(linha, sizeof(linha), file) != NULL) {
        int id = 0;
        char nome[30] = "";
        float preco = 0.0;

        // Lê os dados da linha
        if (sscanf(linha, "%d;%29[^;];%f", &id, nome, &preco) == 3) {
            // Verifica se o ID lido é o mesmo do parâmetro
            if (id == Id) {
                strcpy(pizza->Nome, nome);
                pizza->Preco = preco;
                break; // Pizza encontrada, sair do loop
            }
        }
    }

    fclose(file);


    return pizza;
}

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
void editar_pizza_CRUD(int *qnt){
    char novo_nome[30], novo_tamanho;
    int id_alteracao_pizza, posicao_alteracao_pizza = -1, opcao=0, id_novo_ing;
    char linha[200];

    FILE *arquivo = fopen("Pizzas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Pizza *pizza_aux = (Pizza *)malloc((*qnt) * sizeof(Pizza));
    Pizza * pizza2 = (Pizza*)malloc(sizeof(Pizza));
    if (pizza_aux == NULL)
    {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return;
    }

    // Carregar as pizzas do arquivo
    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d;%29[^;];%c;%f", &pizza_aux[i].Id, pizza_aux[i].Nome, &pizza_aux[i].Tamanho, &pizza_aux[i].Preco) == 4)
        {
            // Extrair os ingredientes
            char *ingredientes_part = strchr(linha, ';') + 1;
            ingredientes_part = strchr(ingredientes_part, ';') + 1;
            ingredientes_part = strchr(ingredientes_part, ';') + 1;

            int t = 0;
            char *token = strtok(ingredientes_part, ",");///////////////////////////////////////////////////////
            while (token != NULL && t < 12){ // Limitar a 12 ingredientes
                if(t==0) {
                    token = strchr(token, ';') + 1;
                }

                pizza_aux[i].Ingredientes[t].id = atoi(token);
                // Aqui seria necessário buscar o nome e preço do ingrediente usando o ID em um arquivo ou lista de ingredientes

                pizza2 =  pegaNomeEPrecoToken(pizza_aux[i].Ingredientes[t].id);
                //sprintf(pizza_aux[i].Ingredientes[t].nome, "Ingrediente %s", "NomeAUx" ); // Mock
                //strcpy(pizza_aux[i].Ingredientes[t].nome,NomeAUx);// Mock
                strcpy(pizza_aux[i].Ingredientes[t].nome,pizza2->Nome);
                pizza_aux[i].Ingredientes[t].preco = pizza2->Preco;
                token = strtok(NULL, ",");
                t++;
            }
        }
        i++;
    }
    fclose(arquivo);

    // Exibir pizzas para o usuário escolher qual editar
    visualizar_pizza_CRUD();

    printf("Digite o ID da Pizza a ser alterada: ");
    scanf("%d", &id_alteracao_pizza);
    getchar();

    // Procurar a pizza a ser alterada
    for (i = 0; i < *qnt; i++)
    {
        if (pizza_aux[i].Id == id_alteracao_pizza)
        {
            posicao_alteracao_pizza = i;
            break;
        }
    }

    if (posicao_alteracao_pizza == -1){
        printf("Pizza com ID %d nao encontrada.\n", id_alteracao_pizza);
        free(pizza_aux);
        return;
    }
        do{
        printf("*******************************|\n");
        printf("O que gostaria de alterar ?    |\n");
        printf("*******************************|\n");
        printf(" 1 - Nome da Pizza             |\n");
        printf(" 2 - Tamanho da Pizza          |\n");
        printf(" 3 - Ingredientes da Pizza     |\n");
        printf(" 0 - Sair                      |\n");
        printf("*******************************|\n");

        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Qual o novo nome? ");
            fgets(novo_nome, sizeof(novo_nome), stdin);
            novo_nome[strcspn(novo_nome, "\n")] = '\0'; // Remover o '\n'
            strcpy(pizza_aux[posicao_alteracao_pizza].Nome, novo_nome);
            printf("Nome alterado com sucesso!\n");
            break;

        case 2:
            printf("Qual o novo Tamanho (P, M ou G)? ");
            scanf(" %c", &novo_tamanho);
            pizza_aux[posicao_alteracao_pizza].Tamanho = toupper(novo_tamanho);

            if (pizza_aux[posicao_alteracao_pizza].Tamanho == 'P')
                pizza_aux[posicao_alteracao_pizza].Preco = TAMANHO_PIZZA_PEQUENA;
            else if (pizza_aux[posicao_alteracao_pizza].Tamanho == 'M')
                pizza_aux[posicao_alteracao_pizza].Preco = TAMANHO_PIZZA_MEDIA;
            else if (pizza_aux[posicao_alteracao_pizza].Tamanho == 'G')
                pizza_aux[posicao_alteracao_pizza].Preco = TAMANHO_PIZZA_GRANDE;
            else
                printf("Tamanho invalido!\n");
            printf("Tamanho alterado com sucesso!\n");
            break;

        case 3:
            printf("Ingredientes atuais da pizza:\n");////////////////////////////////////////////////////////
            for (int j = 0; pizza_aux[posicao_alteracao_pizza].Ingredientes[j].id != 0; j++)
            {
                printf("%d - Ingrediente %s (R$ %.2f)\n", pizza_aux[posicao_alteracao_pizza].Ingredientes[j].id,
                       pizza_aux[posicao_alteracao_pizza].Ingredientes[j].nome,
                       pizza_aux[posicao_alteracao_pizza].Ingredientes[j].preco);
            }
            printf("Digite o ID do novo ingrediente para substituir o primeiro ingrediente: ");
            scanf("%d", &id_novo_ing);
            // Atualize o ingrediente selecionado
            pizza_aux[posicao_alteracao_pizza].Ingredientes[0].id = id_novo_ing;
            sprintf(pizza_aux[posicao_alteracao_pizza].Ingredientes[0].nome, "Ingrediente %d", id_novo_ing); // Mock
            pizza_aux[posicao_alteracao_pizza].Ingredientes[0].preco = 0.5;                                  // Mock
            printf("Ingrediente alterado com sucesso!\n");
            break;

        case 0:
            printf("Saindo da edicao...\n");
            break;

        default:
            printf("OPÇAO INVALIDA! DIGITE OUTRA.\n");
            break;
        }
    } while (opcao != 0);

    // Reescrever as pizzas no arquivo
    arquivo = fopen("Pizzas.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar as alterações.\n");
        free(pizza_aux);
        return;
    }

    // Gravar todas as pizzas no arquivo, incluindo as alterações
    for (i = 0; i < *qnt; i++)
    {
        fprintf(arquivo, "%d;%s;%c;%.2f;", pizza_aux[i].Id, pizza_aux[i].Nome, pizza_aux[i].Tamanho, pizza_aux[i].Preco);
        for (int j = 0; j < 12 && pizza_aux[i].Ingredientes[j].id != 0; j++)
        {
            fprintf(arquivo, "%d", pizza_aux[i].Ingredientes[j].id);
            if (j < 11 && pizza_aux[i].Ingredientes[j + 1].id != 0)
            {
                fprintf(arquivo, ",");
            }
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    free(pizza_aux);

    printf("Alteracoes salvas com sucesso!\n");
}///////////////////////////////////////////////////////////////////

void remover_pizza_CRUD(int *qtd) {
    int novaQtd = 0,i=0, id_para_remover;
    Pizza2 *pizza = (Pizza2 *)calloc(*qtd, sizeof(Pizza2));

    if (pizza == NULL) {
        printf("Erro ao alocar memória da pizza.\n");
        return;
    }

    FILE *arquivo = fopen("Pizzas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de pizza.\n");
        free(pizza);
        return;
    }
    // Exibir os ingredientes
    visualizar_pizza_CRUD();
    printf("Digite o ID da pizza a ser removida:\n");getchar();
    scanf("%d",&id_para_remover);
    getchar();
    while (i < (*qtd)) {
        //printf(" i =  %d\n",i);
        char linha[150];

        if (fgets(linha, sizeof(linha), arquivo) != NULL) {
            int Id;
            char Nome[MAX_LENGTH_NAME_PIZZA];
            char Tamanho;
            float Preco;
            char Ingredientes[MAX_INGREDIENTE];

            // Verifique se a linha está no formato esperado
            sscanf(linha, "%d;%29[^;];%c;%f;%29[^\n]", &Id, Nome, &Tamanho, &Preco,Ingredientes );
            //printf("%d - %d;%s;%c;%.2f;%s",i, Id, Nome, Tamanho, Preco,Ingredientes );

            // Comparar o ID lido com o ID para remover
            if (Id !=  id_para_remover) {
                // Se for diferente, mantemos no array
                pizza[novaQtd].Id = Id;
                strcpy(pizza[novaQtd].Nome,Nome);
                pizza[novaQtd].Tamanho = Tamanho;
                pizza[novaQtd].Preco = Preco;
                strcpy(pizza[novaQtd].Ingredientes,Ingredientes);
                //printf(" %d - nova qtd dentro %d\n",i,novaQtd);
                novaQtd++;
            }
            i++;
        } else {
            i++;
        }
    }
    //printf(" nova qtd fora  %d\n",novaQtd);

    fclose(arquivo);

    if (novaQtd == (*qtd)) {
        printf("Nenhum ingrediente foi removido. ID nao encontrado.\n");
    } else {
        (*qtd) = novaQtd; // Atualiza a quantidade de ingredientes
        atualiza_pizza(pizza, qtd);
    }

    free(pizza);

}






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





