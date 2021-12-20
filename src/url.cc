#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "url.h"

Url::Url()
{
    _barras = 0;
    _url = "";
}

Url::Url(std::string url)
{
    _barras = 0;
    _url = contarBarras(url);
}

int Url::contarBarras(std::string url)
{
    int counter;
    long unsigned int i = 0;
    for (;i <= url.length(); i++)
    {
        if (url[i] == '/')
            counter++;
    }

    return counter;
}

void Url::SetChave(std::string url){
    _url = url;
    _barras = contarBarras(url);
}
std::string Url::GetChave(){
    return _url;
}
int Url::GetBarras(){
    return _barras;
}
void Url::Imprime(){
    std::cout << _url << std::endl;
}
