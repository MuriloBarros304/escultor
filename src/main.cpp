#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

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
#include <cstring>

int main(int argc, char* argv[]) {
    bool interactiveMode = false;
    std::string inputFilePath = "input.txt"; // default fallback

    if (argc > 1) {
        if (std::strcmp(argv[1], "-i") == 0) {
            interactiveMode = true;
        } else {
            inputFilePath = argv[1];
        }
    }

    if (!interactiveMode) {
        std::cout << "--- Modo de Arquivo ---" << std::endl;
        std::cout << "Lendo arquivo: " << inputFilePath << std::endl;
        ReadTXT arquivo(inputFilePath.c_str());
        Sculptor figura(arquivo.getX(), arquivo.getY(), arquivo.getZ());
        arquivo.draw(figura);
        figura.writeOFF("output.off");
        std::cout << "Arquivo exportado com sucesso para output.off!" << std::endl;
        return 0;
    }

    // Modo interativo
    ReadTXT leitor;
    Sculptor* figura = nullptr;
    FILE* geomviewPipe = nullptr;
    
    std::cout << "--- Modo Interativo ---" << std::endl;
    std::cout << "Digite 'dim nx ny nz' para criar a matriz inicial." << std::endl;
    std::cout << "Comandos: putvoxel, cutvoxel, putbox, cutbox, putsphere, cutsphere, putellipsoid, cutellipsoid" << std::endl;
    std::cout << "Digite 'sair' para encerrar." << std::endl;

    while (true) {
        std::string linhaDigitada;
        if (!std::getline(std::cin, linhaDigitada)) break; // Sai se EOF
        
        if (linhaDigitada == "sair" || linhaDigitada == "exit") {
            if (geomviewPipe) {
                fprintf(geomviewPipe, "(exit)\n");
                fflush(geomviewPipe);
            }
            break;
        }
        
        if (linhaDigitada.empty()) continue;

        if (linhaDigitada.find("salvar") == 0) {
            if (figura != nullptr) {
                std::stringstream ss(linhaDigitada);
                std::string cmdName;
                std::string filename = "output";
                
                ss >> cmdName; // reads "salvar"
                std::string arg;
                if (ss >> arg) { // reads filename if provided
                    filename = arg;
                }
                
                // Remove .off extension if it exists to avoid .off.off
                if (filename.length() >= 4 && filename.substr(filename.length() - 4) == ".off") {
                    filename = filename.substr(0, filename.length() - 4);
                }
                
                filename += ".off";
                
                figura->writeOFF(filename.c_str());
                std::cout << "Matriz salva como " << filename << std::endl;
            } else {
                std::cout << "Erro: Você precisa definir as dimensões primeiro com 'dim nx ny nz'." << std::endl;
            }
            continue;
        }

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
                
                figura->writeOFF("interativo.off");
                if (geomviewPipe == nullptr) {
                    // Inicia o geomview e se conecta a ele via pipe, lendo comandos da entrada padrão
                    geomviewPipe = popen("geomview -c - 2>/dev/null", "w");
                    if (geomviewPipe) {
                        std::cout << "Geomview aberto automaticamente para preview!" << std::endl;
                    }
                }
                if (geomviewPipe) {
                    // Envia comando GCL para carregar a figura na tela
                    fprintf(geomviewPipe, "(geometry Escultura {< interativo.off})\n");
                    fflush(geomviewPipe);
                }
            }
        } else {
            if (figura != nullptr) {
                cmd->draw(*figura); // Aplica a figura/corte na matriz 3D instantaneamente
                delete cmd;        // Libera a memória para não vazar RAM
                
                figura->writeOFF("interativo.off"); // Atualiza o arquivo
                std::cout << "Comando aplicado! interativo.off foi atualizado." << std::endl;
                
                if (geomviewPipe) {
                    // Atualiza a malha instantaneamente no geomview
                    fprintf(geomviewPipe, "(geometry Escultura {< interativo.off})\n");
                    fflush(geomviewPipe);
                }
            } else {
                std::cout << "Erro: Você precisa definir as dimensões primeiro com 'dim nx ny nz'." << std::endl;
                delete cmd;
            }
        }
    }
    
    if (geomviewPipe != nullptr) {
        pclose(geomviewPipe);
    }

    if (figura != nullptr) {
        delete figura;
    }

    return 0;
}
