package pers.candy.learning.implement.hashmap;

public interface Map<K, V> {

    public V getValue(K key);
    
    public boolean put(K key, V value);
    
    public int size();

    boolean contains(K key);
    
    boolean remove(K key);
    
}
