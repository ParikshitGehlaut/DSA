import java.util.*;

public class Main {
    static void HashMapsMethods() {
        // Syntax
        Map<String, Integer> map = new HashMap<>();
        // adding elements
        map.put("Parikshit", 19);
        map.put("Jeet", 19);
        map.put("Pranav", 19);
        map.put("Tarun", 19);
        map.put("Varun", 19);

        // getting values using key
        System.out.println(map.get("Parikshit"));// 19
        System.out.println(map.get("Yash"));// returns null

        // changing values using key
        map.put("Jeet", 20);
        System.out.println(map.get("Jeet"));

        // removing the pair
        System.out.println(map.remove("Pranav")); // 19
        System.out.println(map.remove("Yash")); // null

        // add pair if it doesn't exits before
        map.putIfAbsent("Yash", 20);

        // method to get all keys
        System.out.println(map.keySet());

        // method to get all values
        System.out.println(map.values());

        // method to see all entries
        System.out.println(map.entrySet());

        // traversing all the entries in hashmap
        for (String key : map.keySet()) {
            System.out.println(key + " " + map.get(key));
        }

    }

    public static void main(String[] args) {
        HashMapsMethods();
    }
}