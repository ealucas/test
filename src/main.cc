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
    // Escalonador escalonador;
    // std::ifstream arquivo;
    // arquivo.open(argv[1]);
    // std::string comando;
    // while (arquivo >> comando)
    // {
    //     if (comando == "ADD_URLS")
    //     {
    //         int numeroHosts;
    //         std::string url;
    //         arquivo >> numeroHosts;
    //         for (int i = 0; i < numeroHosts; i++)
    //         {
    //             arquivo >> url;
    //             escalonador.adicionaUrls(url);
    //         }
    //         escalonador.imprimeUrls();
    //     }
    // }
    // std::string james = "teste#aaaaa";
    // std::cout << james.find('#') << std::endl;
    // std::cout << james.erase(5) << std::endl;
    // arquivo.close();
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