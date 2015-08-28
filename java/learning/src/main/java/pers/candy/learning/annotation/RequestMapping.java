package pers.candy.learning.annotation;

import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Inherited;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Documented
@Target({ElementType.FIELD, ElementType.METHOD, ElementType.TYPE})
@Inherited
@Retention(RetentionPolicy.RUNTIME)
public @interface RequestMapping {

    public String method() default Method.GET;
    
    public String name() default "";
    
    public String value() default "/";
    
}
