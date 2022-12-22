#include "rf_service.h"

using namespace aidl::devtitans::rf;                // RfService (rf_service.cpp)
using namespace std;                                       // std::shared_ptr
using namespace ndk;                                       // ndk::SharedRefBase

int main() {
    LOG(INFO) << "Iniciando Rf AIDL Service ...";

    ABinderProcess_setThreadPoolMaxThreadCount(0);

    shared_ptr<RfService> rf_service = SharedRefBase::make<RfService>();

    const string instance = std::string() + IRf::descriptor + "/default";   // devtitans.rf.IRf/default
    binder_status_t status = AServiceManager_addService(rf_service->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK);

    LOG(INFO) << "Rf AIDL Service iniciado com nome: " << instance;
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE;                                   // Não deve chegar nunca aqui
}
