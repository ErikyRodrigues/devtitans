package devtitans.rfapp;

import androidx.appcompat.app.AppCompatActivity;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.*;
import android.os.RemoteException;
import devtitans.rfmanager.RfManager;                          // Biblioteca do Manager

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "DevTITANS.RfApp";

    private TextView textStatus, textLuminosity;
    private EditText editLed;
    private RfManager manager;                                        // Atributo para o Manager

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textStatus =     findViewById(R.id.textStatus);                      // Acessa os componentes da tela

        manager = RfManager.getInstance();

        updateAll(null);
    }

    public void updateAll(View view) {
        Log.d(TAG, "Atualizando dados do dispositivo ...");

        textStatus.setText("Atualizando ...");
        textStatus.setTextColor(Color.parseColor("#c47e00"));

        try {
            int status = manager.connect();                                  // Executa o método connect via manager
            if (status == 0) {
                textStatus.setText("Desconectado");
                textStatus.setTextColor(Color.parseColor("#73312f"));
            }
            else if (status == 1) {
                textStatus.setText("Conectado");
                textStatus.setTextColor(Color.parseColor("#6d790c"));
            }
            else {
                textStatus.setText("ERRO");
                textStatus.setTextColor(Color.parseColor("#207fb5"));
            }

        } catch (android.os.RemoteException e) {
            Toast.makeText(this, "Erro ao acessar o Binder!", Toast.LENGTH_LONG).show();
            Log.e(TAG, "Erro atualizando dados:", e);
        }

    }

    public void openGate(View view) {
        try {
            manager.enviarSinal(10);
        } catch (android.os.RemoteException e) {
            Toast.makeText(this, "Erro ao enviar sinal", Toast.LENGTH_LONG).show();
        }
    }

    public void closeGate(View view) {
        try {
            manager.enviarSinal(9);
        } catch (android.os.RemoteException e) {
            Toast.makeText(this, "Erro ao enviar sinal", Toast.LENGTH_LONG).show();
        }
    }
}