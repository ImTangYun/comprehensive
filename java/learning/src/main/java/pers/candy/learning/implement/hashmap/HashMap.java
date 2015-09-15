package pers.candy.learning.implement.hashmap;

public class HashMap<K, V> implements Map<K, V> {

    static class Entry {
        
        Object key;
        
        Object value;
        
        int hash;
        
        Entry next;
    }

    
    Entry table[];
    
    int size;
    
    public HashMap() {
        size = 0;
        table = new Entry[17];
        for (int i = 0; i < table.length; ++i) {
            table[i] = null;
        }
    }

    @Override
    public boolean contains(K key) {
        
        int hash = getHash(key);
        int index = hash % table.length;
        Entry entry = table[index];
        if (entry == null) {
            return false;
        }
        if (key.equals(entry.key)) {
            return true;
        }
        while (entry.next != null) {
            if (key.equals(entry.next.key)) {
                return true;
            }
            entry = entry.next;
        }
        return false;
    }

    @Override
    public V getValue(K key) {
        
        int hash = getHash(key);
        int index = hash % (table.length - 1);
        Entry entry = table[index];
        if (entry == null) {
            return null;
        }
        if (key.equals(entry.key)) {
            return (V)entry.value;
        }
        while (entry.next != null) {
            if (key.equals(entry.next.key)) {
                return (V) entry.next.value;
            }
            entry = entry.next;
        }
        return null;
    }

    @Override
    public boolean put(K key, V value) {
        
        if (2 * size > table.length) {
            realloc(table.length * 2 + 1);
        }
        
        int hash = getHash(key);
        int index = hash % (table.length - 1);
        ++size;
        Entry entry = new Entry();
        entry.hash = hash;
        entry.key = key;
        entry.value = value;
        insertNode(entry, index);
        return true;
    }
    
    private void insertNode(Entry entry, int index) {
        entry.next = null;
        if (table[index] == null) {
            table[index] = entry;
            return;
        }
        Entry tmp = table[index];
        while (tmp.next != null) {
            if (tmp.key.equals(entry.key)) {
                tmp.value = entry.value;
                return;
            }
            tmp = tmp.next;
        }
        if (tmp.key.equals(entry.key)) {
            tmp.value = entry.value;
        } else {
            tmp.next = entry;
        }
    }

    @Override
    public int size() {
        return size;
    }
    
    private int getHash(K key) {
        int code = key.hashCode();
        if (code >= 0)
            return code;
        return -code;
    }

    @Override
    public boolean remove(K key) {
        if (3 * size < table.length && size > 35) {
            int half = table.length / 2;
            int newSize = (half % 2 != 0) ? half:(half + 1);
            realloc(newSize);
        }
        
        int hash = getHash(key);
        int index = hash % (table.length - 1);
        Entry entry = table[index];
        if (entry == null) {
            return false;
        }
        
        if (entry.key.equals(key)) {
            table[index] = entry.next;
            --size;
            return true;
        }
        
        while (entry.next != null) {
            if (entry.next.key.equals(key)) {
                entry = entry.next.next;
                --size;
                return true;
            }
            entry = entry.next;
        }
        
        return false;
    }
    
    private void realloc(int newSize) {
        System.out.println("realloc, newSize:" + newSize + ", size:" + size);
        Entry[] tmp = table;
        size = 0;
        table = new Entry[newSize];
        for (int i = 0; i < table.length; ++i) {
            table[i] = null;
        }
        for (int i = 0; i < tmp.length; ++i) {
            insertEntry(tmp[i]);
        }
        tmp = null;
    }
    
    private void insertEntry(Entry entry) {
        if (entry == null) {
            return;
        }
        Entry tmp = entry;
        while (tmp != null) {
            ++size;
            Entry node = tmp;
            int index = node.hash % (table.length - 1);
            tmp = tmp.next;
            insertNode(node, index);
        }
    }
}
