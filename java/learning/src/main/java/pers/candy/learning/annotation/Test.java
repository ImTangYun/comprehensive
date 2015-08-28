package pers.candy.learning.annotation;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;


public class Test {

    public static void main(String[] args) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
        Apple apple = new Apple();
        Method[] methods = Apple.class.getDeclaredMethods();
        for (Method method: methods) {
            MyAnn myAnn = null;
            if ((myAnn = method.getAnnotation(MyAnn.class)) != null) {
                method.invoke(apple, myAnn.name());
            } else {
                method.invoke(apple, "----");
            }
        }
        String outString = null + "hello";
        System.out.println("/".split("/").length);
    }

}
