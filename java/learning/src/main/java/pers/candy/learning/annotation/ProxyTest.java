package pers.candy.learning.annotation;

public class ProxyTest {

    public static void main(String[] args) throws Exception {
        Proxy proxy = new Proxy();

        proxy.mappingRequest();
        
        System.out.println("=================");
        
        proxy.processRequest("method=get;uri=test/foo1/;data=hello i am Candy, how are you! test/foo1/");

        proxy.processRequest("method=post;uri=another/foo2/;data=hello i am Candy, how are you! another/foo2/");
    }
}
