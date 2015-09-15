package pers.candy.learning.implement.hashmap;

import pers.candy.learning.implement.hashmap.HashMap.Entry;

public class Test {

    public static void main(String[] args) {

        Map<String, String> map = new HashMap<>();
        
        // 写入
        map.put("Candy", "Dangyun");
        map.put("lenovo", "PC");
        map.put("baidu", "search");
        
        // 读取
        System.out.println(map.getValue("lenovo"));
        System.out.println(map.getValue("Candy"));
        System.out.println(map.getValue("baidu"));
        System.out.println(map.size());
        
        // 迭代遍历
        for (Entry entry: map.entries()) {
            System.out.println("key:" + entry.key + ", value:" + entry.value);
        }
        
        // 移除
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
        for (Entry entry: map.entries()) {
            System.out.println("key:" + entry.key + ", value:" + entry.value);
        }
    }

}
