package pers.candy.learning.annotation;
import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Inherited;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;



@Documented
@Target({ElementType.FIELD, ElementType.METHOD})
@Inherited
@Retention(RetentionPolicy.RUNTIME)
public @interface MyAnn {

    public String name() default "Candy";
}
