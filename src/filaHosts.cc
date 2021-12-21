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


void FilaHosts::Enfileira(ListaUrls item){ // inserts a new item
    FilaCelula *nova;
    nova = new FilaCelula();
    nova->item.CopyList(item);
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
    aux.CopyList(frente->prox->item);
    p = frente;
    frente = frente->prox;
    p->item.Limpa();
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
    item.SetTamanho(0); 
    prox = nullptr;
}

FilaHosts::~FilaHosts(){
    Limpa();
    delete frente;
}