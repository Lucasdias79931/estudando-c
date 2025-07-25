#include "Pessoa.h"
#include <iostream>

Pessoa::Pessoa(const std::string& nome, int idade) : nome(nome), idade(idade) {}

void Pessoa::imprimir() const {
    std::cout << "Nome: " << nome << ", Idade: " << idade << std::endl;
}
