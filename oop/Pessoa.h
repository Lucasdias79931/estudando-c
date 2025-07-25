#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
public:
    Pessoa(const std::string& nome, int idade);
    void imprimir() const;

private:
    std::string nome;
    int idade;
};

#endif



