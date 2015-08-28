package pers.candy.learning.annotation;

import java.lang.reflect.InvocationTargetException;
import java.util.Iterator;
import java.util.Set;

public class ProxyTest {

    public static void main(String[] args) throws Exception {
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
        
        proxy.mappingRequest();
        
        System.out.println("=================");
        
        proxy.processRequest("method=get;uri=test/foo1/;data=hello i am Candy, how are you!");

    }
}
