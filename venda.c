#include "venda.h"

Pizza* criaPizzaVenda() {
    Pizza * pizza = (Pizza*)malloc(sizeof(Pizza));
    pizza->Id = -15;
    return pizza;
}
int tamanhoArrayIngredientes(const Pizza*pizza) {
    //vejo o tamanho do array de ingredientes da pizza ja existente
    int tamanhoInicial=0,i=0;
    char linha_ingrediente[100];


    for(int j=0;j<12;j++) {
        FILE *arquivo_ingredientes = fopen("Ingredientes.txt", "r");
        if (arquivo_ingredientes == NULL)
        {
            printf("\nErro ao abrir o arquivo de ingredientes.\n");
        }
        while (fgets(linha_ingrediente, sizeof(linha_ingrediente), arquivo_ingredientes))
        {
            Ingrediente temp_ingrediente;
            if (sscanf(linha_ingrediente, "%d;%29[^;];%f", &temp_ingrediente.id,
                temp_ingrediente.nome,&temp_ingrediente.preco) == 3)
            {


                if ( pizza->Ingredientes[j].id == temp_ingrediente.id){
                    tamanhoInicial++;
                    printf(" * %s   %d ---\n",pizza->Ingredientes[j].nome,tamanhoInicial);
                }


            }
        }
        fclose(arquivo_ingredientes);
    }

    return tamanhoInicial;
}

Pizza* venda_pizza_cardapio(int *qtd) {
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

            if(id == id_selecionado) {
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
                                pizza_selecionada->Ingredientes[quantidadeDeIngrediente].id =temp_ingrediente.id;
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
                *qtd = quantidadeDeIngrediente;
            }
        }
    }
    fclose(arquivo_pizza);
    return pizza_selecionada;
}

void venda_pizza_adiciona_ingrediente(Pizza*pizza,int* qtd) {

    //mostra os ingredientes e faz o loop ate que o cliente n queira mais
    //ou atinja o max de ingredientes
    char resp,linha[100];int id_ingrediente_selecionado=1;
    printf("");
    visualizar_ingrediente_CRUD();
    while (*qtd < 12 && id_ingrediente_selecionado!=0){
        printf("Digite o ID do ingrediente (0 para finalizar): ");
        scanf("%d", &id_ingrediente_selecionado);
        getchar();
        if (id_ingrediente_selecionado != 0) {
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
                    if (temp_ingrediente.id == id_ingrediente_selecionado)
                    {
                        strcpy(pizza->Ingredientes[*qtd].nome,temp_ingrediente.nome);
                        pizza->Ingredientes[*qtd].preco = temp_ingrediente.preco;
                        (*qtd)++;
                        encontrado = 1;
                        break;
                    }
                }
            }
            fclose(arquivo_ingredientes);

            if (!encontrado)
            {
                printf("Ingrediente com ID %d nao encontrado.\n", id_ingrediente_selecionado);
            }
        }else{printf(" Cadastro de ingredientes finalizado!! ");}
    }
    if(*qtd == 12)
        printf(" Limite MAXIMO de ingredientes atingido!! ");


}
void venda_pizza(Pizza*pizza, int *quantidadeDeIngrediente) {
    printf("%d",*quantidadeDeIngrediente);
    //if(pizza != NULL)
    //    visualiza_pizza_venda(pizza,quantidadeDeIngrediente);
    float valorFinalPizza=0.0;
    valorFinalPizza += pizza->Preco;


    for(int i=0;i<*quantidadeDeIngrediente;i++){
        valorFinalPizza += pizza->Ingredientes[i].preco;
    }

    printf("Pizza Selecionada:\n");
    printf("%s [%c] R$%.2f\n",pizza->Nome,
        pizza->Tamanho,
        pizza->Preco);
    printf("   Ingredientes:\n");
    for(int j=0;j<*quantidadeDeIngrediente;j++) {
        printf("      %s : R$%.2f\n",pizza->Ingredientes[j].nome,
        pizza->Ingredientes[j].preco);
    }
    printf("TOTAL:\n");
    printf("\tVendida por: R$%.2f\n",valorFinalPizza);
}
/*O preço final da pizza deve incluir o valor base mais o custo de
qualquer ingrediente extra.*/



int menu_venda(Pizza*pizza){
    int NumeroOperacaoVenda = 0;
    printf("\n");
    printf("************************************|\n");
    printf("VENDA(s):                           |\n");
    if(pizza->Id  != -15) {
        printf("************************************|\n");
        printf("Pizza selecionada:                  |\n");
        printf("%s [%c]                       \n",pizza->Nome, pizza->Tamanho);
    }
    printf("************************************|\n");
    printf(" 1 - Selecionar pizza do cardapio   |\n");
    printf(" 2 - Adicionar mais ingrediente(s)  |\n");
    printf(" 3 - Realizar a venda               |\n");
    printf(" 0 - Fechar VENDA(s)                |\n");
    printf("************************************|\n");
    scanf("%d",&NumeroOperacaoVenda);

    return NumeroOperacaoVenda;

}