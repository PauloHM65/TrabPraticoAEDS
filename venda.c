#include "venda.h"

Pizza* criaPizzaVenda() {
    Pizza * pizza = (Pizza*)malloc(sizeof(Pizza));
    return pizza;
}

//vender pizza

Pizza* venda_pizza_cardapio() {
    Pizza* pizza_selecionada = (Pizza*)malloc(sizeof(Pizza));
    char n,tamanho_selecionado;
    visualizar_pizza_CRUD();
    printf("Qual o ID da pizza escolhida?\n");
    scanf("%c",&n);getchar();
    printf("P - R$40,00   |   M - R$50,00   |   G - R$60,00\n");
    printf("Qual o tamanho?\n");
    scanf("%c",&tamanho_selecionado);getchar();
    tamanho_selecionado = toupper(tamanho_selecionado);

    FILE *arquivo = fopen("Pizzas.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");

    }

    char linha[200];
    while (fgets(linha, sizeof(linha), arquivo))
    {
        int id;
        char nome[30], tamanho;
        float preco;
        char ingredientes_ids[100];

        // Lê os dados da pizza, incluindo os IDs dos ingredientes
        if (sscanf(linha, "%d;%29[^;];%c;%f;%99[^\n]", &id, nome, &tamanho, &preco, ingredientes_ids) == 5)
        {
            pizza_selecionada->Id = id;
            strcpy(pizza_selecionada->Nome,nome);
            pizza_selecionada->Tamanho = tamanho_selecionado;
            toupper(tamanho);
            if(tamanho == 'P')
                pizza_selecionada->Preco = TAMANHO_PIZZA_PEQUENA;
            if(tamanho == 'M')
                pizza_selecionada->Preco = TAMANHO_PIZZA_MEDIA;
            if(tamanho == 'G')
                pizza_selecionada->Preco = TAMANHO_PIZZA_GRANDE;
            // Exibe os ingredientes
            char *token = strtok(ingredientes_ids, ",");
            int quantidadeDeIngrediente=0;
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
                    if (sscanf(linha_ingrediente, "%d;%29[^;];%f", &temp_ingrediente.id,
                        temp_ingrediente.nome,&temp_ingrediente.preco) == 3)
                    {
                        if (temp_ingrediente.id == id_ingrediente)
                        {
                            //prnitf("%s (R$%.2f), ", temp_ingrediente.nome, temp_ingrediente.preco);
                            strcpy(pizza_selecionada->Ingredientes[quantidadeDeIngrediente].nome,temp_ingrediente.nome);
                            pizza_selecionada->Ingredientes[quantidadeDeIngrediente].preco = temp_ingrediente.preco;
                            quantidadeDeIngrediente++;
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


    return pizza_selecionada;
}

void venda_pizza_adiciona_ingrediente(Pizza*pizza) {
    //vejo o tamanho do array de ingredientes da pizza ja existente
    int tamanhoInicial=0,i=0;
    while(tamanhoInicial ==0) {
        if(pizza->Ingredientes[i].nome == '\0' || pizza->Ingredientes[i].nome == NULL ) {
            tamanhoInicial = i;
        }
        i++;
    }

    //mostra os ingredientes e faz o loop ate que o cliente n queira mais
    //ou atinja o max de ingredientes
    char resp,linha[100];int id_ingrediente=0;
    visualizar_ingrediente_CRUD();
    while (tamanhoInicial < 12 || id_ingrediente!=0){

        printf("Digite o ID do ingrediente (0 para finalizar): ");
        scanf("%d", &id_ingrediente);
        getchar();

        if (id_ingrediente != 0) {
            // Reabrir o arquivo de ingredientes para buscar pelo ID
            FILE*arquivo_ingredientes = fopen("Ingredientes.txt", "r");
            if (arquivo_ingredientes == NULL)
            {
                printf("Erro ao abrir o arquivo de ingredientes.\n");
            }

            int encontrado = 0;
            while (fgets(linha, sizeof(linha), arquivo_ingredientes))
            {
                Ingrediente temp_ingrediente;
                if (sscanf(linha, "%d;%29[^;];%f", &temp_ingrediente.id, temp_ingrediente.nome, &temp_ingrediente.preco) == 3)
                {
                    if (temp_ingrediente.id == id_ingrediente)
                    {
                        strcpy(pizza->Ingredientes[tamanhoInicial].nome,temp_ingrediente.nome);
                        pizza->Ingredientes[tamanhoInicial].preco = temp_ingrediente.preco;
                        tamanhoInicial++;
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
        }else{printf(" Cadastro de ingredientes finalizado!! ");}
    }

}
void venda_pizza(Pizza*pizza) {
    int quantidadeDeIng=0,i=0;
    float valorFinalPizza=0.0;
    valorFinalPizza += pizza->Preco;

    while(quantidadeDeIng ==0) {
        if(!(pizza->Ingredientes[i].nome == '\0' || pizza->Ingredientes[i].nome == NULL) ) {
            valorFinalPizza+=pizza->Ingredientes[i].preco;
            i++;
        }else{quantidadeDeIng = i;}
    }

    printf("Pizza de:\n");
    printf("%s [%c]\n",pizza->Nome,
        pizza->Tamanho);
    printf("\tIngredientes: ");
    for(int i=0;i<quantidadeDeIng;i++) {
        printf(" %s %.2f",pizza->Ingredientes[i].nome,
        pizza->Ingredientes[i].preco);
    }
    printf("Vendida por: %.2f\n",valorFinalPizza);



}
/*O preço final da pizza deve incluir o valor base mais o custo de
qualquer ingrediente extra.*/



int menu_venda() {
    int NumeroOperacaoVenda = 0;
    printf("\n");
    printf("************************************|\n");
    printf("VENDA(s):                           |\n");
    printf("************************************|\n");
    printf(" 1 - Selecionar pizza do cardapio   |\n");
    printf(" 2 - Adicionar mais ingradiente(s)  |\n");
    printf(" 3 - Ralizar a conta e vender       |\n");
    printf(" 0 - Fechar VENDA(s)                |\n");
    printf("************************************|\n");
    scanf("%d",&NumeroOperacaoVenda);

    return NumeroOperacaoVenda;

}