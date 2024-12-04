#include "venda.h"

Pizza* criaPizzaVenda() {
    Pizza * pizza = (Pizza*)malloc(sizeof(Pizza));
    return pizza;
}
void visualiza_pizza(Pizza* pizza, int qtdIng) {
    int quantidadeDeIng=0;
    float valorFinalPizza=0.0;
    valorFinalPizza += pizza->Preco;


    for(int i=0;i<qtdIng;i++){
            valorFinalPizza += pizza->Ingredientes[i].preco;
    }

    printf("Pizza Selecionada:\n");
    printf("%s [%c] R$%.2f\n",pizza->Nome,
        pizza->Tamanho,
        pizza->Preco);
    printf("   Ingredientes:\n");
    for(int j=0;j<qtdIng;j++) {
        printf("      %s : R$%.2f\n",pizza->Ingredientes[j].nome,
        pizza->Ingredientes[j].preco);
    }
    printf("TOTAL:\n");
    printf("\tVendida por: R$%.2f\n",valorFinalPizza);
}
//vender pizza

Pizza* venda_pizza_cardapio() {
    Pizza* pizza_selecionada = (Pizza*)malloc(sizeof(Pizza));
    int id_selecionado;
    char tamanho_selecionado;
    visualizar_pizza_CRUD();
    printf("Qual o ID da pizza escolhida?\n");
    scanf("%d",&id_selecionado);getchar();
    printf("P - R$40,00   |   M - R$50,00   |   G - R$60,00\n");
    printf("Qual o tamanho?\n");
    scanf("%c",&tamanho_selecionado);getchar();
    tamanho_selecionado = toupper(tamanho_selecionado);

    FILE *arquivo_pizza = fopen("Pizzas.txt", "r");

    if (arquivo_pizza == NULL)
    {
        printf("Erro ao abrir o arquivo\n");

    }

    char linha[200];
    int quantidadeDeIngrediente=0; // esta sendo usado no index dos ing pegados doarquivo
    // coloquei ela aqui para ser paremetro na visualiza_pizza_venda();
    while (fgets(linha, sizeof(linha), arquivo_pizza)){
        int id;
        char nome[30], tamanho;
        float preco;
        char ingredientes_ids[100];

        // Lê os dados da pizza, incluindo os IDs dos ingredientes
        if (sscanf(linha, "%d;%29[^;];%c;%f;%99[^\n]", &id, nome, &tamanho, &preco, ingredientes_ids) == 5){

            if(id == id_selecionado) {printf("achou o id %d\n" , id);
                pizza_selecionada->Id = id;
                strcpy(pizza_selecionada->Nome,nome);
                pizza_selecionada->Tamanho = tamanho_selecionado;
                if(tamanho_selecionado == 'P')
                    pizza_selecionada->Preco = TAMANHO_PIZZA_PEQUENA;
                if(tamanho_selecionado == 'M')
                    pizza_selecionada->Preco = TAMANHO_PIZZA_MEDIA;
                if(tamanho_selecionado == 'G')
                    pizza_selecionada->Preco = TAMANHO_PIZZA_GRANDE;
                // Exibe os ingredientes
                char *token = strtok(ingredientes_ids, ",");
                quantidadeDeIngrediente=0;
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
                                pizza_selecionada->Ingredientes[quantidadeDeIngrediente].nome,
                                pizza_selecionada->Ingredientes[quantidadeDeIngrediente].preco;
                                quantidadeDeIngrediente++;
                                break;
                            }
                        }
                    }
                    fclose(arquivo_ingredientes);

                    token = strtok(NULL, ",");
                }
            }
        }
    }
    fclose(arquivo_pizza);
    if(pizza_selecionada != NULL)
        visualiza_pizza(pizza_selecionada,quantidadeDeIngrediente);
    return pizza_selecionada;
}

void venda_pizza_adiciona_ingrediente(Pizza*pizza) {
    //vejo o tamanho do array de ingredientes da pizza ja existente
    int tamanhoInicial=0,i=0;
    while(tamanhoInicial ==0) {
        if(pizza->Ingredientes[i].nome[0] == '\0' || pizza->Ingredientes[i].nome == NULL ) {
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
}
/*O preço final da pizza deve incluir o valor base mais o custo de
qualquer ingrediente extra.*/



int menu_venda(){
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