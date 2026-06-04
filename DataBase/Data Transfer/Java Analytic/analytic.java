package DataBase.DataTransfer.JavaAnalytic;

import java.util.Base64;
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;

public class Analytic {
    private static final String ALGORITHM = "AES";
    private byte[] secretKey;

    public Analytic(String key) {
        this.secretKey = key.getBytes();
    }

    public String encryptData(String data) throws Exception {
        SecretKeySpec keySpec = new SecretKeySpec(secretKey, ALGORITHM);
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.ENCRYPT_MODE, keySpec);
        byte[] encrypted = cipher.doFinal(data.getBytes());
        return Base64.getEncoder().encodeToString(encrypted);
    }

    public void logEvent(String eventName, String payload) {
        System.out.println("Event: " + eventName + " | Payload: " + payload);
    }
}
