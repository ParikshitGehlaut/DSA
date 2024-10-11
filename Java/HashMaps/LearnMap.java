import java.util.*;

class LearnMap {
    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();

        map.put("us", "United States");
        map.put("in", "India");
        map.put("uk", "United Kingdom");

        for (Map.Entry<String, String> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }
    }
}
