package pers.candy.learning.urlcode;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.net.URLEncoder;

public class EncodeDecode {

    public static void main(String[] args) throws UnsupportedEncodingException {
        // TODO Auto-generated method stub

        System.out.println(URLDecoder.decode("%2Ftest2%2Fleofs-1.2.10-1.el6.x86_64.rpm"));
        String urlString = "jdsflkd中文 空格？？？、阿斯顿会计师        ";
        String encodeed = URLEncoder.encode(urlString, "UTF-8");
        String decoded = URLDecoder.decode(encodeed, "UTF-8");
        System.out.println("origin:" + urlString + ", encodeed:" + encodeed + ",decodeed:" + decoded);
    }

}
