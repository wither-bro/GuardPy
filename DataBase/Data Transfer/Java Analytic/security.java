package DataBase.DataTransfer.JavaAnalytic;

import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.security.SecureRandom;

public class Security {
    private static final int KEY_SIZE = 256;

    public static byte[] generateKey() throws Exception {
        KeyGenerator keyGen = KeyGenerator.getInstance("AES");
        keyGen.init(KEY_SIZE, new SecureRandom());
        SecretKey secretKey = keyGen.generateKey();
        return secretKey.getEncoded();
    }

    public static boolean verifyIntegrity(byte[] data, byte[] signature) {
        if (data == null || signature == null) return false;
        return java.security.MessageDigest.isEqual(data, signature);
    }
}
