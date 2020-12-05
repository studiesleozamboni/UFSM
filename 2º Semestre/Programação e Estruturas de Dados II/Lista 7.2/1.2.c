/* Problema 2
 * Escreva um programa que recebe duas listas encadeadas de inteiros e efetue os seguintes passos:
 * a) Verifique se as listas estão ordenadas;
 * b) Ordene as listas, caso não estejam ordenadas;
 * c) Mescle os elementos da segunda lista na primeira, mantendo a ordenação na lista final.
 */
// O exercício que eu demorei 2 dias para fazer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listaNo{
    struct listaNo *anterior;
    int valor;
    struct listaNo *proximo;
}ListaNo;

typedef struct lista {
    struct listaNo *inicio;
    struct listaNo *final;
}Lista;

Lista *cria(void) {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->inicio = lista->final = NULL;
    return lista;
}

void insere(Lista *lista, int valor) {
    ListaNo *listaNo = (ListaNo *) malloc(sizeof(Lista));
    listaNo->valor = valor;

    if (!lista->inicio) {
        listaNo->proximo = NULL;
        listaNo->anterior = NULL;
        lista->inicio = listaNo;
        lista->final = listaNo;
    }
    else {
        listaNo->proximo = NULL;
        listaNo->anterior = lista->final;
        lista->final->proximo = listaNo;
        lista->final = listaNo;
    }
}

void imprime(Lista *lista) {
    ListaNo *percorre = lista->inicio;
    while (percorre) {
        printf("Valor %d\n", percorre->valor);
        percorre = percorre->proximo;
    }
}

void insereOrdenado(Lista *lista, int valor) {
    ListaNo *percorre = lista->inicio;
    ListaNo *anterior = NULL;
    ListaNo *novo = (ListaNo *) malloc(sizeof(ListaNo));
    novo->valor = valor;

    if (!lista->inicio) {
        insere(lista, valor);
        return;
    }

    while (percorre) {
        if (percorre->valor > valor)
            break;
        anterior = percorre;
        percorre = percorre->proximo;
    }

    if (!anterior) {
        novo->proximo = percorre;
        novo->anterior = NULL;
        percorre->anterior = novo;
        lista->inicio = novo;
    }
    else {
        novo->proximo = percorre;
        novo->anterior = anterior;
        anterior->proximo = novo;
        if (!percorre)
            lista->final = novo;
    }
}

bool verificaOrdenada(Lista *lista) {
    ListaNo *percorre = lista->inicio;

    while (percorre) {
        if (percorre->anterior && percorre->valor < percorre->anterior->valor)
            return false;
        percorre = percorre->proximo;
    }

    return true;
}

void ordenar(Lista *lista) {
    int valorAnterior;
    for (ListaNo *percorreAntes = lista->inicio; percorreAntes; percorreAntes = percorreAntes->proximo) {
        for (ListaNo *percorre = percorreAntes->proximo; percorre; percorre = percorre->proximo) {
            if (percorreAntes->valor > percorre->valor) {
                valorAnterior = percorreAntes->valor;
                percorreAntes->valor = percorre->valor;
                percorre->valor = valorAnterior;
            }
        }
    }#include <stdio.h>
      #include <stdlib.h>

    typedef struct lista{
        int valor;
        struct lista *proximo;
    }Lista;

    Lista *cria(void) {
        Lista *lista = (Lista *) malloc(sizeof(Lista));
        lista->proximo = NULL;
        return lista;
    }

    void insere(Lista *lista, int valor) {
        Lista *novo = (Lista *) malloc(sizeof(Lista));
        novo->valor = valor;
        novo->proximo = lista->proximo;
        lista->proximo = novo;
    }

    int verificarOrdenada(Lista *lista) {
        Lista *anterior = NULL;
        lista = lista->proximo;
        while (lista) {
            if (anterior && lista->valor > anterior->valor)
                return 0;
            anterior = lista;
            lista = lista->proximo;
        }
        return 1;
    }

    void ordena(Lista *lista) {
        int menorValor;
        for (Lista *percorre = lista->proximo; percorre; percorre = percorre->proximo)
            for (Lista *percorreProximo = percorre->proximo; percorreProximo; percorreProximo = percorreProximo->proximo) {
                if (percorre->valor < percorreProximo->valor) {
                    menorValor = percorre->valor;
                    percorre->valor = percorreProximo->valor;
                    percorreProximo->valor = menorValor;
                }
            }
    }

    Lista *mesclar(Lista *listaA, Lista *listaB) {
        Lista *listaMesclada = cria();
        listaA = listaA->proximo; listaB = listaB->proximo;

        for (size_t i = 0; ; ++i) {
            if (!listaA && !listaB)
                break;
            if (i % 2 == 0) {
                if (listaA) {
                    insere(listaMesclada, listaA->valor);
                    listaA = listaA->proximo;
                }
                else {
                    insere(listaMesclada, listaB->valor);
                    listaB = listaB->proximo;
                }
            }
            else if (listaB) {
                insere(listaMesclada, listaB->valor);
                listaB = listaB->proximo;
            }
        }

        ordena(listaMesclada);
        return listaMesclada;
    }

    void imprime(Lista *lista) {
        lista = lista->proximo;
        puts("Lista:");
        while (lista) {
            printf("valor %d\n", lista->valor);
            lista = lista->proximo;
        }
        puts("Fim!");
    }
    int main(void) {
        Lista *lista = cria();
        insere(lista, 1);
        insere(lista, 2);
        insere(lista, 3);
        imprime(lista);

        if (verificarOrdenada(lista))
            puts("Ordenada");
        else
            puts("Nao ordenada");

        puts("\nListaB:");
        Lista *listaB = cria();
        insere(listaB, 4);
        insere(listaB, 6);
        insere(listaB, 5);
        imprime(listaB);

        if (verificarOrdenada(listaB))
            puts("Ordenada");
        else
            ordena(listaB);

        puts("\nListaB ordenada:");
        imprime(listaB);

        puts("\nListaC mesclada:");
        Lista *listaC = mesclar(lista, listaB);
        imprime(listaC);

        if (verificarOrdenada(listaC))
            puts("Ordenada");
        else
            puts("Nao ordenada");

        system("pause");
    }
}

Lista *mesclar(Lista *lista1, Lista *lista2) {
    Lista *listaMesclada = cria();
    ListaNo *listaPrimeira = lista1->inicio;
    ListaNo *listaSegunda = lista2->inicio;

    for (size_t i = 0; ; ++i) {
        if (!listaPrimeira && !listaSegunda)
            return listaMesclada;
        if (listaPrimeira) {
            if (i % 2 == 0) {
                insereOrdenado(listaMesclada, listaPrimeira->valor);
                listaPrimeira = listaPrimeira->proximo;
            }
            else if (listaSegunda) {
                insereOrdenado(listaMesclada, listaSegunda->valor);
                listaSegunda = listaSegunda->proximo;
            }
        }
        else {
            insereOrdenado(listaMesclada, listaSegunda->valor);
            listaSegunda = listaSegunda->proximo;
        }
    }
}

int main(void) {
    Lista *lista1 = cria();
    insereOrdenado(lista1, 2);
    insereOrdenado(lista1, 1);
    insereOrdenado(lista1, 4);
    insereOrdenado(lista1, 3);

    imprime(lista1);

    if (verificaOrdenada(lista1))
        printf("Ordenada\n");
    else
        printf("Nao ordenada\n");

    Lista *lista2 = cria();
    insere(lista2, 5);
    insere(lista2, 7);
    insere(lista2, 6);
    insereOrdenado(lista2, 8);

    imprime(lista2);

    if (verificaOrdenada(lista2))
        printf("Ordenada\n");
    else {
        printf("Nao ordenada\n");
        ordenar(lista2);
    }

    imprime(lista2);

    if (verificaOrdenada(lista2))
        printf("Ordenada\n");
    else
        printf("Nao ordenada\n");

    puts("Lista Mesclada");
    Lista *listaMesclada = mesclar(lista1, lista2);
    insereOrdenado(listaMesclada, 10);
    insereOrdenado(listaMesclada, 9);

    imprime(listaMesclada);

    if (verificaOrdenada(listaMesclada))
        printf("Ordenada\n");
    else
        printf("Nao ordenada\n");

    system("pause");
}