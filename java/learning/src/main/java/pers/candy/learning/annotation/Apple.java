package pers.candy.learning.annotation;

public class Apple {

    @MyAnn(name = "Tang")
    private String name;
    
    @MyAnn(name = "TangYun")
    public String getName(String in) {
        System.out.println(in);
        return name;
    }
    
    public String getUser(String in) {
        System.out.println(in);
        return name;
    }
}
