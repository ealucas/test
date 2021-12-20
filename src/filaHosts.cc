#include <stdio.h>
#include <iostream>
#include <string>
#include "url.h"
#include "listaUrls.h"
#include "filaHosts.h"

FilaHosts::FilaHosts() : Fila()
{
    frente = new FilaCelula; //celula cebeça;
    tras = frente;
}

FilaHosts::~FilaHosts(){
    Limpa();
    delete frente;
}

void FilaHosts::Enfileira(ListaUrls item){ // inserts a new item
    FilaCelula *nova;
    nova = new FilaCelula();
    nova->item = item;
    tras->prox = nova;  //last    
    tras = nova;
    tamanho++;
}

ListaUrls FilaHosts::Desenfileira(){  // removes an item
    FilaCelula *p;
    ListaUrls aux;

    if (tamanho == 0){
        throw "Fila está vazia!";
    }
    aux = frente->prox->item;
    p = frente;
    frente = frente->prox;
    delete p;
    tamanho--;
    return aux;
}
void FilaHosts::Limpa(){
    FilaCelula *p;

    p = frente->prox;
    while(p!=nullptr){
        frente->prox = p->prox;
        delete p;
        p = frente->prox;
    }
    tamanho = 0;
    tras = frente;
}

FilaCelula::FilaCelula()
{
    // item = new ListaUrls();
    prox = nullptr;
}