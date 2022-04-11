/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Guilherme Gouveia
 *
 * Created on 13 de Fevereiro de 2021, 12:00
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
//#include <cstdio>
#include "tree.h"
using namespace std;

/*
 * 
 */


void mountTree(noArvore **raiz){
    int valor;
    noArvore *tmp;
    bool block = true;
    ifstream data ("dados.txt");
    if (!data.is_open() || data.eof()){
        cout << "Erro ao abrir o arquivo, ou ele está vazio" << endl;
        abort();
    };
    do {
        data >> valor;
        printf("%d-", valor);
        tmp = insere(*raiz, valor);
        if (block) {
            *raiz = tmp; // poderia criar uma funcao inicia arvore e tratar a de insercao para a primeira intancia
            block = false;
        }
    } while (!data.eof());
    puts("");
    data.close();
}

int main(int argc, char** argv) {
    noArvore *raiz = NULL;
    
    mountTree(&raiz);
    
    pos_ordem(raiz, imprime);
    
    puts("\nRemovendo");
    remove(raiz, 5);
    remove(raiz, 332);
    remove(raiz, 234);
    remove(raiz, 8);
    remove(raiz, 23);
   
    pos_ordem(raiz, imprime);
    
    puts("\nEncerrando");
    pos_ordem(raiz, encerra);
    
    return 0;
}

