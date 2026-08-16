#include <iostream>
#include <string>

#include "readtxt.h"
#include "sculptor.h"

/**
 * \mainpage
 * @brief Escultor 3D utilizando blocos com C++, projeto requerido na segunda
 * unidade da disciplina: Programação Avançada no Departamento de Engenharia de
 * Computação e Automação da Universidade Federal do Rio Grande do Norte.
 * \authors
 * Murilo de Lima Barros \n
 * Leonardo Pessoa Cavalcanti
 */
int main(void) {
    ReadTXT leitor;
    Sculptor* figura = nullptr;
    
    std::cout << "--- Modo Interativo ---" << std::endl;
    std::cout << "Digite 'dim nx ny nz' para criar a matriz inicial." << std::endl;
    std::cout << "Comandos: putvoxel, cutvoxel, putbox, cutbox, putsphere, cutsphere, putellipsoid, cutellipsoid" << std::endl;
    std::cout << "Digite 'sair' para encerrar." << std::endl;

    while (true) {
        std::string linhaDigitada;
        if (!std::getline(std::cin, linhaDigitada)) break; // Sai se EOF
        
        if (linhaDigitada == "sair" || linhaDigitada == "exit") {
            break;
        }
        
        if (linhaDigitada.empty()) continue;

        // Usa sua classe para interpretar a linha que veio do terminal
        FiguraGeometrica* cmd = leitor.parseLine(linhaDigitada);

        if (cmd == nullptr) {
            // Se cmd eh nullptr, pode ser o comando "dim" ou comando invalido
            if (linhaDigitada.find("dim") != std::string::npos) {
                if (figura != nullptr) {
                    delete figura;
                }
                figura = new Sculptor(leitor.getX(), leitor.getY(), leitor.getZ());
                std::cout << "Matriz 3D criada com sucesso!" << std::endl;
            }
        } else {
            if (figura != nullptr) {
                cmd->draw(*figura); // Aplica a figura/corte na matriz 3D instantaneamente
                delete cmd;        // Libera a memória para não vazar RAM
                
                figura->writeOFF("interativo.off"); // Atualiza o arquivo
                std::cout << "Comando aplicado! interativo.off foi atualizado." << std::endl;
                
                // ...aqui iria o código do popen para mandar o geomview atualizar a tela...
            } else {
                std::cout << "Erro: Você precisa definir as dimensões primeiro com 'dim nx ny nz'." << std::endl;
                delete cmd;
            }
        }
    }
    
    if (figura != nullptr) {
        delete figura;
    }

    return 0;
}