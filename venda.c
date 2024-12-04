#include "venda.h"

Pizza* criaPizzaVenda() {
    Pizza * pizza = (Pizza*)malloc(sizeof(Pizza));
    return pizza;
}

//vender pizza

Pizza* venda_pizza_cardapio(int*qtd) {
    Pizza* pizza_selecionada = (Pizza*)malloc(sizeof(Pizza));
    int n=0;
    char tamanho_selecionado;
    visualizar_pizza_CRUD();
    printf("Qual o ID da pizza escolhida?\n");
    scanf("%d",&n);
    printf("P R$40,00  |  M R$50,00  |  G R$60,00\n");
    printf("Qual o tamanho?\n");
    scanf("%c",&tamanho_selecionado);

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
            if(tamanho == 'P')
                pizza_selecionada->Preco = pizza_pequena;
            if(tamanho == 'M')
                pizza_selecionada->Preco = pizza_media;
            if(tamanho == 'G')
                pizza_selecionada->Preco = pizza_grande;
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
Pizza* venda_pizza_adiciona_ingrediente(Pizza*pizza,int*qtd) {
    Pizza* pizza2 = (Pizza*)malloc(sizeof(Pizza));


    return pizza2;
}
void venda_pizza(Pizza*pizza,int*qtd){}
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