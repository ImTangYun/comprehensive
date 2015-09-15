package pers.candy.learning.implement.hashmap;

import java.util.List;

import pers.candy.learning.implement.hashmap.HashMap.Entry;

public interface Map<K, V> {

    public V getValue(K key);
    
    public boolean put(K key, V value);
    
    public int size();

    public boolean contains(K key);
    
    public boolean remove(K key);
    
    public List<Entry> entries();
    
}
