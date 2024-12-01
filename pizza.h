
#ifndef PIZZA_H
#define PIZZA_H

#endif //PIZZA_H

typedef struct pizza{
    int Id;
    char Nome[30];
    char Tamanho;//P,M,G
    float Preco;
    Ingrediente Ingredientes[];//Array com os ingredientes padrão da pizza
}pizza;
