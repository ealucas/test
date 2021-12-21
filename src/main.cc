#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "url.h"
#include "listaUrls.h"
#include "filaHosts.h"

int main(int argc, char **argv)
{

    Url a,b,c,d,e;
    a.SetChave("3///");
    b.SetChave("2//");
    c.SetChave("1/");
    d.SetChave("4////");
    e.SetChave("0");
    ListaUrls lista;
    lista.Insere(a);
    lista.Insere(b);
    lista.Insere(c);
    lista.Insere(d);
    lista.Insere(e);
    lista.Imprime();
    FilaHosts fila; //
    fila.Enfileira(lista);
    return 0;
}