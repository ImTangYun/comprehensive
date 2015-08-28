package pers.candy.learning.annotation;

import java.util.Iterator;
import java.util.Set;

public class ProxyTest {

    public static void main(String[] args) {
        Proxy proxy = new Proxy();

        Set<Class<?>> set = Proxy.getClasses("pers.candy.learning.annotation");
        Iterator<Class<?>> it = set.iterator();
        while (it.hasNext()) {
            Class<?> str = it.next();
            if ((str.getAnnotation(RequestMapping.class)) != null) {
                System.out.println(str.getAnnotation(RequestMapping.class));
                System.out.println(str.getCanonicalName());
            }

        }

    }
}
