#pragma once

#include <android-base/logging.h>
#include <android/binder_process.h>
#include <android/binder_manager.h>

#include <aidl/devtitans/rf/BnRf.h>            // Criado pelo AIDL automaticamente

#include "rf_lib.h"                                   // Classe Rf (biblioteca)

using namespace devtitans::rf;

namespace aidl::devtitans::rf {

class RfService : public BnRf {
    public:
        ndk::ScopedAStatus connect(int32_t* _aidl_return) override;
        ndk::ScopedAStatus enviarSinal(int32_t in_valorSinal, bool* _aidl_return) override;

    private:
        Rf rf;                                 // Biblioteca
};

}
