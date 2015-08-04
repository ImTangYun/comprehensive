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