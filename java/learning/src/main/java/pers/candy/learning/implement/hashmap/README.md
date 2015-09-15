 实现一个hashmap，包含如下接口：
 
	// 知道key取value 
    public V getValue(K key);
    // 插入键值对
    public boolean put(K key, V value);
    // 获取对象个数
    public int size();
	// 查看key是否存在
    public boolean contains(K key);
    // 移除key对应的键值对
    public boolean remove(K key);
    // 获取对象列表，用于遍历map
    public List<Entry> entries();