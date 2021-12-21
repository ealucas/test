#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "url.h"
#include "listaUrls.h"

TipoCelula::TipoCelula()
{
    url.SetChave(" ");
    prox = nullptr;
}
ListaUrls::ListaUrls() : Lista()
{
    primeiro = new TipoCelula();
    ultimo = primeiro;
};
ListaUrls::~ListaUrls()
{
    Limpa();
    delete primeiro;
}
// TipoCelula ListaUrls::Posiciona(int pos, bool antes = false)
// {
//     TipoCelula *p;
//     int i;
//     if ((pos > tamanho) || (pos <= 0))
//         throw "ERRO: POSICAO INVALIDA!";
//     p = primeiro;
//     for (i = 1; i < pos; i++)
//     {
//         p = p->prox;
//     }
//     if (!antes)
//     {
//         p = p->prox;
//     }

//     return p;
// }

void ListaUrls::Limpa()
{
    TipoCelula *p;
    p = primeiro->prox;
    while (p != nullptr)
    {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

void ListaUrls::Insere(Url url)   // insert
{
    TipoCelula *right, *left;
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->url = url;
    left = primeiro;
    right = primeiro->prox;
    if(Vazia()){
        InsereInicio(url);
        return;
    }
    while (right != nullptr)
    {
        int barras = url.GetBarras();
        if (right->url.GetBarras() > barras){
            left->prox = nova;
            nova->prox = right;
            break;
        }
        right = right->prox;
        left = left->prox;
    }
    tamanho++;
    if (nova->prox == nullptr)
    {
        ultimo->prox = nova;
    }
}
void ListaUrls::Imprime()     // PRINTS list
{
    TipoCelula *p;
    p = primeiro->prox;
    while (p != nullptr)
    {
        p->url.Imprime();
        p = p->prox;
    }
    printf("\n");
}

void ListaUrls::InsereInicio(Url url) // inserts at the beggining
{
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->url = url;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;
    if (nova->prox == nullptr)
    {
        ultimo = nova;
    }
}

void ListaUrls::SetTamanho(int num){
     tamanho = num;
}

ListaUrls *  ListaUrls::CopyList(ListaUrls lista){
    ListaUrls *aux;
    aux->primeiro = lista.primeiro;
    aux->ultimo = lista.ultimo;
    aux->SetTamanho(lista.getTamanho());
    return aux;
}