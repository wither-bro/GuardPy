package DataBase.DataTransfer.JavaAnalytic;

import javax.crypto.Cipher;
import javax.crypto.spec.GCMParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.SecureRandom;
import java.util.Base64;

public class Analytic {
    private static final String ALGORITHM = "AES/GCM/NoPadding";
    private static final int TAG_LENGTH = 128;
    private static final int IV_LENGTH = 12;
    private final SecretKeySpec keySpec;

    public Analytic(byte[] key) {
        this.keySpec = new SecretKeySpec(key, "AES");
    }

    public String encryptData(String data) throws Exception {
        byte[] iv = new byte[IV_LENGTH];
        new SecureRandom().nextBytes(iv);
        
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.ENCRYPT_MODE, keySpec, new GCMParameterSpec(TAG_LENGTH, iv));
        
        byte[] cipherText = cipher.doFinal(data.getBytes());
        byte[] combined = new byte[iv.length + cipherText.length];
        
        System.arraycopy(iv, 0, combined, 0, iv.length);
        System.arraycopy(cipherText, 0, combined, iv.length, cipherText.length);
        
        return Base64.getEncoder().encodeToString(combined);
    }

    public String decryptData(String encryptedData) throws Exception {
        byte[] combined = Base64.getDecoder().decode(encryptedData);
        byte[] iv = new byte[IV_LENGTH];
        System.arraycopy(combined, 0, iv, 0, IV_LENGTH);
        
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.DECRYPT_MODE, keySpec, new GCMParameterSpec(TAG_LENGTH, iv));
        
        byte[] plainText = cipher.doFinal(combined, IV_LENGTH, combined.length - IV_LENGTH);
        return new String(plainText);
    }

    public void logEvent(String event, String payload) throws Exception {
        String encrypted = encryptData(payload);
        System.out.println("E:" + event + "|P:" + encrypted);
    }
}
