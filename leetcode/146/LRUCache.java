import java.util.HashMap;
import java.util.Map;

public class LRUCache {
    public static class DLinkedNode {
        int key;
        int value;
        DLinkedNode prev;
        DLinkedNode next;
        public DLinkedNode() {}
        public DLinkedNode(int _key, int _value) {key = _key; value = _value;}
    }

    private Map<Integer, DLinkedNode> cache = new HashMap<Integer, DLinkedNode>();
    private int size;
    private int capacity;
    private DLinkedNode head, tail;

    public LRUCache(int capacity) {
        this.size = 0;
        this.capacity = capacity;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if (!cache.containsKey(key)) {
            return -1;
        }

        DLinkedNode oldNode = cache.get(key);
        deleteNode(oldNode);
        addHead(oldNode);
        return oldNode.value;
    }
    
    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            DLinkedNode oldNode = cache.get(key);
            deleteNode(oldNode);
            addHead(oldNode);
            oldNode.value = value;
        } else {
            DLinkedNode newNode = new DLinkedNode(key, value);
            cache.put(key, newNode);
            addHead(newNode);
            this.size++;        

            if (this.size > this.capacity) {
                cache.remove(this.tail.prev.key);
                removeTail();
                this.size--;
            }
        }
    }
    
    private void addHead(DLinkedNode node) {
        DLinkedNode next = this.head.next;

        node.next = next;
        next.prev = node;

        this.head.next = node;
        node.prev = this.head;
    }

    private void removeTail() {
        DLinkedNode needDeleteNode = this.tail.prev;
        deleteNode(needDeleteNode);
        needDeleteNode = null;
    }

    private void deleteNode(DLinkedNode node) {
        DLinkedNode prev = node.prev;
        DLinkedNode next = node.next;

        prev.next = next;
        next.prev = prev;        
    }

    public static void main(String[] args) {
        LRUCache lRUCache = new LRUCache(2);
        lRUCache.put(1, 1); 
        lRUCache.put(2, 2); 
        System.out.println(lRUCache.get(1));     
        lRUCache.put(3, 3); 
        System.out.println(lRUCache.get(2));   
        lRUCache.put(4, 4); 
        lRUCache.get(1); 
        lRUCache.get(3); 
        lRUCache.get(4); 
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */