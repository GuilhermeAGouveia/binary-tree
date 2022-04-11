/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "tree.h"
#include <cstdio>
#define NULL nullptr

noArvore * insere(noArvore *raiz, int valor) {
    if (raiz == NULL) {
        noArvore *no = new (noArvore);
        no->valor = valor;
        no->dir = no->esq = NULL;
        return no;
    }
    if (raiz->valor > valor) {
        raiz->esq = insere(raiz->esq, valor);
    } else {
        raiz->dir = insere(raiz->dir, valor);
    }
    return raiz;
}

noArvore * busca(noArvore *raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) return raiz;
    if (raiz->valor > valor) {
        return busca(raiz->esq, valor);
    } else {
        return busca(raiz->dir, valor);
    }
}

noArvore * buscaPai(noArvore *raiz, noArvore *no) {
    if (raiz == no) return NULL;
    if (raiz->esq == no || raiz->dir == no) return raiz;
    if (raiz->valor > no->valor) {
        return buscaPai(raiz->esq, no);
    } else {
        return buscaPai(raiz->dir, no);
    }

}

noArvore * removeRaiz(noArvore *raiz) {
    noArvore *sub, *tmp;
    if (raiz->esq == NULL || raiz->dir == NULL) {
        raiz = raiz->esq ? raiz->esq : raiz->dir;
        return raiz;
    }
    sub = raiz->esq;
    if (sub->dir == NULL) {
        sub->dir = raiz->dir;
        raiz = sub;
        return raiz;
    }
    while (sub->dir != NULL) {
        tmp = sub;
        sub = sub->dir;
    }
    tmp->dir = sub->esq;
    raiz->valor = sub->valor;
    delete sub;
    return raiz;
}

noArvore * remove(noArvore *raiz, int valor) {
    noArvore *no = busca(raiz, valor);
    //printf("(%d)\n", no->valor);
    if (no) {
        noArvore *pai = buscaPai(raiz, no);
        if (pai) {
            if (pai->esq == no) {
                pai->esq = removeRaiz(no);

            } else {
                pai->dir = removeRaiz(no);
            }
        } else {
            raiz = removeRaiz(raiz); // o noh a ser removido eh a propria raiz, encontrado no inicio, poderia passar no (como o feito) ou a raiz como parametro
        }
        return no;
    }
    return NULL;
}

int imprime(noArvore *no) {
    printf("(%p)->(%d)\n", no, no->valor);
    return 0;
}

int encerra(noArvore *no) {
    printf("\nEncerrando noh: (%p)->(%d)", no, no->valor);
    delete no;
    return 0;
}

void pos_ordem(noArvore *raiz, int (*funcPtr)(noArvore *)) {
    if (raiz->esq != NULL) pos_ordem(raiz->esq, funcPtr);
    if (raiz->dir != NULL) pos_ordem(raiz->dir, funcPtr);
    funcPtr(raiz);
}