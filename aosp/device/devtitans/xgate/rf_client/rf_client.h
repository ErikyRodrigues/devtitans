#pragma once                      // Inclui esse cabeçalho apenas uma vez

#include <iostream>               // std::cout (char-out) e std::endl (end-line)
#include <string.h>               // Função strcmp
#include <stdlib.h>               // Função atoi

#include "rf_lib.h"        // Classe Rf

namespace devtitans::rf {  // Pacote que a classe abaixo pertence

class RfClient {           // Classe

    public:
        void start(int argc, char **argv);

};

} // namespace
