package pers.candy.learning;

import java.util.ArrayList;
import java.util.List;

class A implements Cloneable {
	
	public List<String> getLisData() {
		return lisData;
	}

	public void setLisData(List<String> lisData) {
		this.lisData = lisData;
	}

	public String getString() {
		return string;
	}

	public void setString(String string) {
		this.string = string;
	}

	private List<String> lisData;
	
	String string;
	
	public Object clone() {
		A o = null;
		try {
			o = (A)super.clone();
			
			o.lisData = new ArrayList<String>();
			for (String str : lisData) {
				String str1 = new String(str);
				o.lisData.add(str1);
			}
			o.string = new String(string);
		} catch (CloneNotSupportedException e) {
			e.printStackTrace();
		}
		return o;
	}
	
}

public class HowToCopyObject {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		A a = new A();
		List<String> list = new ArrayList<String>();
		list.add("str1");
		list.add("str2");
		a.setLisData(list);
		String string = "string of A1";
		a.setString(string);
		
		A a1 = (A)a.clone();
		a1.getLisData().add("str3");
		System.out.println("a:" + a + "a1:" + a1);
		System.out.println("a.lisData:" + a.getLisData() + " a1.lisData:" + a1.getLisData());
	}

}
