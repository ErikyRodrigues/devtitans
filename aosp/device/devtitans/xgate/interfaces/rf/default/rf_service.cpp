#include "rf_service.h"

namespace aidl::devtitans::rf {
    ndk::ScopedAStatus RfService::connect(int32_t* _aidl_return) {
        *_aidl_return = this->rf.connect();
        LOG(INFO) << "connect(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus RfService::enviarSinal(int32_t in_valorSinal, bool* _aidl_return) {
        *_aidl_return = this->rf.enviarSinal(in_valorSinal);
        LOG(INFO) << "enviarSinal( " << in_valorSinal << "): " << (*_aidl_return ? "true" : "false");
        return ndk::ScopedAStatus::ok();
    }

}
