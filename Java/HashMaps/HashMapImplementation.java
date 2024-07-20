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

        // Test case 1: Insert a few elements and check the size
        mp.put("a", 1);
        mp.put("b", 2);
        mp.put("c", 3);
        assert mp.size() == 3 : "Test case 1 failed";

        // Test case 2: Get the value of an existing key
        assert mp.get("b") == 2 : "Test case 2 failed";

        // Test case 3: Get the value of a non-existing key
        assert mp.get("college") == null : "Test case 3 failed";

        // Test case 4: Remove an existing key and check size
        assert mp.remove("c") == 3 : "Test case 4 failed";
        assert mp.size() == 2 : "Test case 4 failed";

        // Test case 5: Remove a non-existing key
        assert mp.remove("c") == null : "Test case 5 failed";

        // Test case 6: Insert a key with an existing value (update the value)
        mp.put("b", 20);
        assert mp.get("b") == 20 : "Test case 6 failed";

        // Test case 7: Insert a key again and ensure it's updated
        mp.put("a", 10);
        assert mp.get("a") == 10 : "Test case 7 failed";

        // Test case 8: Check the size after updates
        assert mp.size() == 2 : "Test case 8 failed";

        // Test case 9: Remove all elements and check size
        assert mp.remove("a") == 10 : "Test case 9 failed";
        assert mp.remove("b") == 20 : "Test case 9 failed";
        assert mp.size() == 0 : "Test case 9 failed";

        // Test case 10: Get from an empty map
        assert mp.get("a") == null : "Test case 10 failed";
        assert mp.get("b") == null : "Test case 10 failed";

        // Test case 11: Insert and remove in a larger set of operations
        mp.put("x", 100);
        mp.put("y", 200);
        mp.put("z", 300);
        assert mp.size() == 3 : "Test case 11 failed";
        assert mp.remove("y") == 200 : "Test case 11 failed";
        assert mp.get("z") == 300 : "Test case 11 failed";
        assert mp.get("x") == 100 : "Test case 11 failed";
        assert mp.size() == 2 : "Test case 11 failed";

        // Test case 12: Handling null values
        MyHashMap<String, String> nullMap = new MyHashMap<>();
        nullMap.put("nullValue", null);
        assert nullMap.get("nullValue") == null : "Test case 12 failed";
        nullMap.put("nullValue", "notNull");
        assert "notNull".equals(nullMap.get("nullValue")) : "Test case 12 failed";
        assert nullMap.size() == 1 : "Test case 12 failed";

        System.out.println("All test cases passed!");

    }
}
