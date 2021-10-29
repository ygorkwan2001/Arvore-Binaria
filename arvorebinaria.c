#include <stdio.h>
#include <stdlib.h>

struct item
{
    int cod;
};

typedef struct item Item;

struct NO{
    Item info;
    struct NO *esquerda;
    struct NO *direita;
};

typedef struct NO ArvoreBinaria;

ArvoreBinaria *create(){
    return NULL;
}

int vazia(ArvoreBinaria* raiz){
    if(raiz == NULL){
        printf("\nLista Vazia\n");
        return 1;
    }else{
        printf("\nLista nao esta vazia\n");
        return 0;
    }
}

Item criacaodoitem(int cod){
    Item info;
    info.cod = cod;
    return info;
}

ArvoreBinaria *inserir(ArvoreBinaria *raiz, Item x){
    if(raiz == NULL){
        ArvoreBinaria *novo = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));
        novo->info = x;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }else{
        if(x.cod > raiz->info.cod){
            raiz -> direita = inserir(raiz->direita,x);
        }else if(x.cod < raiz->info.cod){
            raiz -> esquerda = inserir(raiz->esquerda,x);
        }
    }
    return raiz;
}

void imprimir(ArvoreBinaria *raiz){
    if(raiz != NULL){
        printf("\n%d", raiz->info.cod);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

ArvoreBinaria *buscar(ArvoreBinaria *raiz, int cod){
    if(raiz != NULL){
        if(raiz->info.cod == cod ){
            return cod;
        }else{
            if(cod > raiz->info.cod){
                return buscar(raiz->direita, cod);
            }else{
                return buscar(raiz->esquerda, cod);
            }
        }
        return NULL;
    }
}

ArvoreBinaria* liberar(ArvoreBinaria *raiz){
    if(raiz != NULL){
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
    return NULL;
}


int main(int argc, char const *argv[])
{
    ArvoreBinaria *raiz = create();
    raiz = inserir(raiz, criacaodoitem(24));
    raiz = inserir(raiz, criacaodoitem(10));
    raiz = inserir(raiz, criacaodoitem(32));
    raiz = inserir(raiz, criacaodoitem(5));
    raiz = inserir(raiz, criacaodoitem(29));
    raiz = inserir(raiz, criacaodoitem(12));
    raiz = inserir(raiz, criacaodoitem(35));
    imprimir(raiz);
    vazia(raiz);
    printf("\n----------------------------------------\n");
    ArvoreBinaria *busca = buscar(raiz, 12);
    if(busca == NULL){
        printf("\n>> Elemento  nao encontrado\n");
    }else{
        printf("\n>> Elemento %d encontrado\n", busca);
    }
    printf("\n----------------------------------------\n");
    raiz = liberar(raiz);
    vazia(raiz);
    printf("\nLista Liberada\n");
    printf("\n----------------------------------------\n");
    
    return 0;
}
