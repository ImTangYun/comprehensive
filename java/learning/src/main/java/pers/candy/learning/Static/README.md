 静态方法大家应该都比较熟悉，在这里主要谈一下静态方法在继承时的一些注意事项。

1、父类方法如果是静态方法，子类不能覆盖为非静态方法；

2、父类方法如果是非静态方法，子类不能覆盖为静态方法；

3、父类静态方法可以被覆盖，允许在子类中定义同名的静态方法，但是没有多态。

下面对第3条特性进行一下代码演示：

package pers.candy.learning.Static;
//
//
//
//
//
public class ExtendsStatic {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Father father = new Son();
		father.hello();
		Son son = new Son();
		son.hello();

	}

}

class Father {
	
	public static void hello() {
		System.out.println("hello, i am father");
	}
}

class Son extends Father {
	public static void hello() {
		System.out.println("hello, i am son");
	}
}