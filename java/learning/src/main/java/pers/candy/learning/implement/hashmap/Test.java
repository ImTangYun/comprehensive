package pers.candy.learning.implement.hashmap;

public class Test {

    public static void main(String[] args) {

        Map<String, String> map = new HashMap<>();
        
        map.put("Candy", "Dangyun");
        map.put("lenovo", "PC");
        map.put("baidu", "search");
        
        System.out.println(map.getValue("lenovo"));
        System.out.println(map.getValue("Candy"));
        System.out.println(map.getValue("baidu"));
        System.out.println(map.size());
        
        map.remove("baidu");
        System.out.println(map.getValue("lenovo"));
        System.out.println(map.getValue("Candy"));
        System.out.println(map.getValue("baidu"));
        System.out.println(map.size());
        
        for (int i = 0; i < 7000; ++i) {
            map.put("key" + i, "value" + i);
        }
        
        System.out.println(map.getValue("key3000"));
        System.out.println("size:" + map.size());
    }

}
