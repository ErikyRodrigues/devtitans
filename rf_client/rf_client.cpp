#include "rf_client.h"

using namespace std;                  // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devtitans::rf {      // Entra no pacote devtitans::rf

void RfClient::start(int argc, char **argv) {
    cout << "Cliente RF!" << endl;

    if (argc < 2) {
        cout << "Sintaxe: " << argv[0] << "  " << endl;
        cout << "    Comando: enviarSinal" << endl;
        exit(1);
    }

    Rf rf;             // Classe da biblioteca Rf

    // Comando enviarSinal
    if (!strcmp(argv[1], "enviarSinal")) {
        int valorSinal = atoi(argv[2]);
        if (rf.enviarSinal(valorSinal))
            cout << "Valor do sinal recebido" << valorSinal << endl;
        else
            cout << "Erro ao receber sinal" << endl;
    } else {
        cout << "Comando inválido." << endl;
        exit(1);
    }
}

} // namespace



// MAIN

using namespace devtitans::rf;

int main(int argc, char **argv) {
    RfClient client;
    client.start(argc, argv);
    return 0;
}
