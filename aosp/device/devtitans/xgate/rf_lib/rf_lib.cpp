#include "rf_lib.h"

using namespace std;                                   // Permite usar string, ifstream diretamente ao invés de std::string

namespace devtitans::rf {                       // Entra no pacote devtitans::rf

int Rf::connect() {
    char dirPath[] = "/sys/kernel/rf";
    struct stat dirStat;
    if (stat(dirPath, &dirStat) == 0){
        if (S_ISDIR(dirStat.st_mode)){
            return 1;                                  // Se o diretório existir, retorna 1
        }
    }
    return 0;
}

bool Rf::writeFileValue(string file, int value) {
    int connected = this->connect();

    if (connected == 1) {                          // Conectado. Vamos solicitar o valor ao dispositivo
        string filename = string("/sys/kernel/rf/") + file;
        ofstream file(filename, ios::trunc);            // Abre o arquivo limpando o seu conteúdo

        if (file.is_open()) {                           // Verifica se o arquivo foi aberto com sucesso
            file << value;                              // Escreve o valorSinal no arquivo
            file.close();
            return true;
        }
    }

    // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
    return false;
}

bool Rf::enviarSinal(int valorSinal) {
    return this->writeFileValue("sinal", valorSinal);
}

} // namespace