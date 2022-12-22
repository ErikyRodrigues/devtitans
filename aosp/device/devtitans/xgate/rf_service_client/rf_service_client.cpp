#include <android/binder_manager.h>
#include <aidl/devtitans/rf/IRf.h>
#include <iostream>                             // std::cout e std::endl (end-line)

using namespace aidl::devtitans::rf;     // IRf
using namespace std;                            // std::shared_ptr
using namespace ndk;                            // ndk::SpAIBinder

int main() {
    shared_ptr<IRf> service;
    service = IRf::fromBinder(SpAIBinder(AServiceManager_getService("devtitans.rf.IRf/default")));

    if (!service) {
        cout << "Erro acessando o serviço!" << endl;
        return 1;
    }

    cout << "Serviço funcionando adequadamente." << endl;

    return 0;
}
