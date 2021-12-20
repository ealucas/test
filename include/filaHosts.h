#ifndef FILA_HOSTS
#define FILA_HOSTS
#include <stdio.h>
#include <iostream>
#include <string>
#include "url.h"
#include "listaUrls.h"

class FilaCelula
{
public:
    FilaCelula();

private:
    ListaUrls item;
    FilaCelula *prox;
    friend class FilaHosts;
};

class Fila
{
public:
    Fila() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };

    virtual void Enfileira(ListaUrls item) = 0;
    virtual ListaUrls Desenfileira() = 0;
    virtual void Limpa() = 0;

protected:
    int tamanho;
};

class FilaHosts : public Fila
{
public:
    FilaHosts();
    virtual ~FilaHosts();

    void Enfileira(ListaUrls item);
    ListaUrls Desenfileira();
    void Limpa();

private:
    FilaCelula *frente;
    FilaCelula *tras;
};



#endif