#pragma once                           // Inclui esse cabeçalho apenas uma vez

#include <fstream>                     // Classe ifstream
#include <android-base/properties.h>   // Função GetBoolProperty
#include <sys/stat.h>                  // Função e struct stat
#include <random>                      // Geração de números aleatórios (valores simulados)

using namespace std;                   // Permite usar string diretamente ao invés de std::string

namespace devtitans::rf {       // Pacote RF

class Rf {
    public:
        /**
         * Verifica se o diretório /sys/kernel/smartlamp existe. Se existir
         * o dispositivo SmartLamp está conectado via USB. Caso contrário,
         * verifica a propriedade devtitans.smartlamp.allow_simulated
         * para ver se valores simulados podem ser usados.
         *
         * Retorna:
         *      0: dispositivo não encontrado
         *      1: sucesso
         *      2: simulado (disp. não encontrado, mas usando valores simulados)
         */
        int connect();
        bool enviarSinal(int valorSinal);

    private:
        /**
         * Métodos para escrever valores nos arquivos "led",
         * "ldr" ou "threshold" do diretório /sys/kernel/smartlamp.
         */
        bool writeFileValue(string file, int value);

};

} // namespace
