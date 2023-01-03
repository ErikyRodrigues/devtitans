package devtitans.rfmanager;

import android.util.Log;
import android.os.ServiceManager;
import android.os.IBinder;
import android.os.RemoteException;

import devtitans.rf.IRf;                      // Criado pelo AIDL

public class RfManager {
    private static final String TAG = "DevTITANS.RfManager";
    private IBinder binder;
    private IRf service;

    private static RfManager instance;

    // Construtor. Configura a "instância da classe" (objeto) recém-criada.
    // Note o "private" no construtor. Essa classe só pode ser instanciada dentro desse arquivo.
    private RfManager() {
        Log.d(TAG, "Nova (única) instância do RfManager ...");

        binder = ServiceManager.getService("devtitans.rf.IRf/default");
        if (binder != null) {
            service = IRf.Stub.asInterface(binder);
            if (service != null)
                Log.d(TAG, "Serviço Rf acessado com sucesso.");
            else
                Log.e(TAG, "Erro ao acessar o serviço Rf!");
        }
        else
            Log.e(TAG, "Erro ao acessar o Binder!");
    }

    // Acessa a (única) instância dessa classe. Se ela não existir ainda, cria.
    // Note o "static" no método. Podemos executá-lo sem precisar instanciar um objeto.
    public static RfManager getInstance() {
        if (instance == null)
            instance = new RfManager();

        return instance;
    }

    public int connect() throws RemoteException {
        Log.d(TAG, "Executando método connect() ...");
        return service.connect();
    }

    public boolean enviarSinal(int valorSinal) throws RemoteException {
        Log.d(TAG, "Executando método enviarSinal(" + valorSinal + ") ...");
        return service.enviarSinal(valorSinal);
    }
}
