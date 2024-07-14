import java.util.LinkedList;

public class HashMapImplementation {
    static class MyHashMap<K, V> {
        public static final int DEFAULT_CAPACITY = 4;
        public static final float DEFAULT_LOAD_FACTOR = 0.75f;

        private class Node {
            K key;
            V value;

            Node(K key, V value) {
                this.key = key;
                this.value = value;
            }
        }

        private int n; // the number of entries in map
        private LinkedList<Node>[] buckets;

        private void initBuckets(int N) {
            // N -> Capacity
            buckets = new LinkedList[N];
            for (int i = 0; i < buckets.length; i++) {
                buckets[i] = new LinkedList<>();
            }
        }

        public MyHashMap() {
            initBuckets(DEFAULT_CAPACITY);
        }

        public int size() {
            // return the number of entries in map
            return n;
        }

        private int HashFunc(K key) {
            int hc = key.hashCode();
            return ((Math.abs(hc)) % buckets.length);
        }

        // traverses the LL and looks for a node with key, if found it returns it's
        // index otherwise it return -1
        private int searchInBucket(LinkedList<Node> l1, K key) {
            for (int i = 0; i < l1.size(); i++) {
                if (l1.get(i).key == key) {
                    return i;
                }
            }
            return -1;
        }

        public void put(K key, V value) {
            int b1 = HashFunc(key);
            LinkedList<Node> currBucket = buckets[b1];

            int e1 = searchInBucket(currBucket, key);

            if (e1 == -1) {
                Node node = new Node(key, value);
                currBucket.add(node);
                n++;
            } else {
                // update case
                Node currNode = currBucket.get(e1);
                currNode.value = value;
            }
        }

        public V get(K key) {
            int b1 = HashFunc(key);
            LinkedList<Node> currBucket = buckets[b1];

            int e1 = searchInBucket(currBucket, key);
            if (e1 == -1) {
                return null;
            }
            return currBucket.get(e1).value;
        }

        public V remove(K key) {
            int b1 = HashFunc(key);
            LinkedList<Node> currBucket = buckets[b1];

            int e1 = searchInBucket(currBucket, key);
            if (e1 == -1) {
                return null;
            }
            V value = currBucket.get(e1).value;
            currBucket.remove(e1);
            n--;
            return value;
        }
    }

    public static void main(String[] args) {
        MyHashMap<String, Integer> mp = new MyHashMap<>();

        mp.put("a", 1);
        mp.put("b", 2);
        mp.put("c", 3);
        System.out.println("Testing size: " + mp.size()); // 3
        System.out.println("Testing get: " + mp.get("b")); // 2
        System.out.println("Testing get: " + mp.get("college")); // null
        System.out.println("Testing remove " + mp.remove("c")); // 3
        System.out.println("Testing size: " + mp.size()); // 2

        // updating c value to 30
        mp.put("c", 30);
        System.out.println("Testing get: " + mp.get("a")); // 2
        System.out.println("Testing get: " + mp.get("b")); // 2
        System.out.println("Testing get: " + mp.get("c")); // 2

    }
}
