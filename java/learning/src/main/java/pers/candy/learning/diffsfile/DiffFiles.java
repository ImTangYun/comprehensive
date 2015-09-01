package pers.candy.learning.diffsfile;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class DiffFiles {

    public static void main(String[] args) throws IOException {

        diff(args[0], args[1]);
    }
    
    public static boolean diff(String path1, String path2) throws IOException {
        
        File file1 = new File(path1);
        File file2 = new File(path2);
        
        if (file1.length() != file2.length()) {
            System.out.println("different: size is not equal!");
            return false;
        }
        
        InputStream inputStream1 = new FileInputStream(file1);
        InputStream inputStream2 = new FileInputStream(file2);
        
        byte[] buf1 = new byte[4096];
        byte[] buf2 = new byte[4096];
        int len1 = 0;
        while (len1 != -1) {
            len1 = inputStream1.read(buf1, 0, 4096);
            int len2 = inputStream2.read(buf2, 0, 4096);
            if (len1 != len2) {
                System.out.println("read length did not equal");
                inputStream1.close();
                inputStream2.close();
                return false;
            }
            for (int i = 0; i < len1; ++i) {
                if (buf1[i] != buf2[i]) {
                    System.out.println("different: some byte diffs");
                    inputStream1.close();
                    inputStream2.close();
                    return false;
                }
            }
        }
        System.out.println("the same file");
        inputStream1.close();
        inputStream2.close();
        return true;
    }

}
