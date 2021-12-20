#ifndef URL
#define URL
#include <string>

class Url{
    public:
        Url();
        Url(std::string url);
        int contarBarras(std::string url);
        void SetChave(std::string url);
        std::string GetChave();
        int GetBarras();
        void Imprime();
    private:
        int _barras;
        std::string _url;

        friend class ListaUrls;
};

#endif