package pers.candy.learning.string;

import java.io.ByteArrayOutputStream;
import java.io.UnsupportedEncodingException;
import java.util.HashMap;
import java.util.Map;

import org.springframework.util.Assert;

public class StringUsage {

    public static void main(String[] args) throws UnsupportedEncodingException {
        // TODO Auto-generated method stub

        // String inputString = "tangyun; Chrome/1.0; Ie/3";
        // System.out.println(inputString.contains("tangyun"));
        // System.out.println(inputString.contains("n; Chro"));
        // System.out.println(inputString.contains("Ie/3"));
        // System.out.println(judgeBrowser("Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.63 Safari/537.36"));
        // String source = "%25%25_____%5E.jar";
//        String source = "%%_____^.jar";
//        System.out.println(decode(source, "utf-8"));
//        String origin = "/files/databox/testtangyun/%%_____^.jar";
        // origin.replace("%%_____^.jar", "%25%25____^.jar");
        // System.out.println(origin);
        qsMap();

    }

    public static void qsMap() {
        String qq = "X-LENOVO-SESS-ID=1276d4a0bb58456eaa65190454469b41"
                + "&uid=2090&overwrite=true&source=file&language=zh&t=1439780453738"
                + "&path_type=ent&from=&prefix_neid=";
        Map<String, String> map = parseUrlQuery(qq);
    }
    
    public static Map<String, String> parseUrlQuery(String query) {
        String[] k_vs = query.split("&");
        Map<String, String> map = new HashMap<String, String>();
        for (int i = 0; i < k_vs.length; ++i) {
            String [] k_v = k_vs[i].split("=");
            if (k_v.length == 1) {
                map.put(k_v[0], null);
            } else {
                map.put(k_v[0], k_v[1]);
            }
        }
        return map;
    }

    public static String judgeBrowser(String agent) {
        if (!agent.contains("MSIE")) {
            if (!agent.contains("Trident")) {
                if (!agent.contains("Firefox")) {
                    if (!agent.contains("Safari")) {
                        return "undefined";
                    } else {
                        if (!agent.contains("Windows NT")) {
                            if (!agent.contains("openframe")) {
                                return "winsafri";
                            } else {
                                return "msie";
                            }
                        } else {
                            return "safari";
                        }
                    }
                } else {
                    return "firefox";
                }
            } else {
                return "msie";
            }
        } else {
            return "msie";
        }
    }

    public static String decode(String source, String encoding)
            throws UnsupportedEncodingException {
        Assert.notNull(source, "Source must not be null");
        Assert.hasLength(encoding, "Encoding must not be empty");
        int length = source.length();
        ByteArrayOutputStream bos = new ByteArrayOutputStream(length);
        boolean changed = false;
        for (int i = 0; i < length; i++) {
            int ch = source.charAt(i);
            if (ch == '%') {
                if ((i + 2) < length) {
                    char hex1 = source.charAt(i + 1);
                    char hex2 = source.charAt(i + 2);
                    int u = Character.digit(hex1, 16);
                    int l = Character.digit(hex2, 16);
                    if (u == -1 || l == -1) {
                        throw new IllegalArgumentException(
                                "Invalid encoded sequence \""
                                        + source.substring(i) + "\"");
                    }
                    bos.write((char) ((u << 4) + l));
                    i += 2;
                    changed = true;
                } else {
                    throw new IllegalArgumentException(
                            "Invalid encoded sequence \"" + source.substring(i)
                                    + "\"");
                }
            } else {
                bos.write(ch);
            }
        }
        return (changed ? new String(bos.toByteArray(), encoding) : source);
    }

}
