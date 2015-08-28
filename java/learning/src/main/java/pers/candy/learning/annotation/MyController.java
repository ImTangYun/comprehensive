package pers.candy.learning.annotation;

import java.util.Map;

@RequestMapping(value = "test/")
public class MyController {

    @RequestMapping(value = "foo1/", method = Method.GET)
    public void foo1(Map data) {
        
        System.out.println("foo1");
        System.out.println("data:" + data.get("data"));
    }

    @RequestMapping(value = "hello/", method = Method.POST)
    public void foo2(Map data) {
        System.out.println("foo2");
        System.out.println("data:" + data.get("data"));
    }
}
