/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tree.h
 * Author: Guilherme Gouveia
 *
 * Created on 13 de Fevereiro de 2021, 12:14
 */

#ifndef TREE_H
#define TREE_H

typedef struct _noArvore{
    int valor;
    _noArvore *esq, *dir;
} noArvore;

noArvore * insere(noArvore *raiz, int valor);
noArvore * remove (noArvore *raiz, int valor);
noArvore * removeRaiz (noArvore *raiz);
noArvore * buscaPai(noArvore *raiz, noArvore *no);
noArvore * busca(noArvore *raiz, int valor);
void pos_ordem(noArvore *raiz, int (*funcPtr)(noArvore *));
int imprime(noArvore *no);
int encerra(noArvore *no);
#endif /* TREE_H */

