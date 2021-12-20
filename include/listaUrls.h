#ifndef LISTA_URLS
#define LISTA_URLS
#include <stdio.h>
#include <iostream>
#include <string>
#include "url.h"

class TipoCelula
{
public:
    TipoCelula();

private:
    Url url;
    TipoCelula *prox;

    friend class ListaUrls; // a ListaUrls pode acessar os membros privados do TIpo Celula
};


class Lista
{
public:
    Lista() { tamanho = 0; };
    int getTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };

protected:
    int tamanho;
};

class ListaUrls : public Lista
{
public:
    ListaUrls();
    ~ListaUrls();
    void Limpa();
    void Imprime();
    void Insere(Url url);
    void InsereInicio(Url url);
    ListaUrls * CopyList();

private:
    TipoCelula *primeiro;
    TipoCelula *ultimo;
    TipoCelula Posiciona(int pos, bool antes);

    friend class Url;
};


#endif