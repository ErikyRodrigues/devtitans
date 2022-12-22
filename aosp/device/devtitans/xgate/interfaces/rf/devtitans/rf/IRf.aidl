package devtitans.rf;

@VintfStability
interface IRf {
        int connect();

        boolean enviarSinal(in int valorSinal);
}
