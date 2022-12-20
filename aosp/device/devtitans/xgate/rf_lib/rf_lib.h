#pragma once                           // Inclui esse cabeçalho apenas uma vez

#include <fstream>                     // Classe ifstream
#include <sys/stat.h>                  // Função e struct stat
#include <random>                      // Geração de números aleatórios (valores simulados)

using namespace std;                   // Permite usar string diretamente ao invés de std::string

namespace devtitans::rf {       // Pacote RF

class Rf {
    public:
        /**
         * Verifica se o diretório /sys/kernel/rf existe. Se existir
         * o dispositivo xgate está conectado via USB.
         *
         * Retorna:
         *      0: dispositivo não encontrado
         *      1: sucesso
         */
        int connect();
        bool enviarSinal(int valorSinal);

    private:
        /**
         * Métodos para escrever valores no arquivo "sinal" do diretório /sys/kernel/rf.
         */
        bool writeFileValue(string file, int value);

};

} // namespace
