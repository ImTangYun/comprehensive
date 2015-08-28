package pers.candy.learning.annotation;

import java.lang.reflect.Method;

public class Function {

    private Method method;
    
    private Object object;
    
    private String uriMethod = pers.candy.learning.annotation.Method.GET;
    
    public String getUriMethod() {
        return uriMethod;
    }

    public void setUriMethod(String uriMethod) {
        this.uriMethod = uriMethod;
    }

    public Method getMethod() {
        return method;
    }

    public void setMethod(Method method) {
        this.method = method;
    }

    public Object getObject() {
        return object;
    }

    public void setObject(Object object) {
        this.object = object;
    }

}
