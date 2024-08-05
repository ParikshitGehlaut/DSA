import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;

class TopKElement {
    public static int[] topKFrequent(int[] nums, int k) {
        if (nums.length == 1)
            return nums;

        Map<Integer, Integer> frequencyMap = new HashMap<>();

        // Count the frequency of each element
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }
        System.out.println(frequencyMap);

        // Create an array of lists (buckets) where the index represents the frequency
        List<Integer>[] buckets = new ArrayList[nums.length + 1];
        for (int i = 0; i <= nums.length; i++) {
            buckets[i] = new ArrayList<>();
        }
        System.out.println();
        // Populate the buckets with the elements based on their frequency
        for (Map.Entry<Integer, Integer> entry : frequencyMap.entrySet()) {
            System.out.println("key " + entry.getKey() + " Value " + entry.getValue());
            int frequency = entry.getValue();
            buckets[frequency].add(entry.getKey());
        }

        // Collect the top k frequent elements from the buckets
        List<Integer> resultList = new ArrayList<>();
        for (int i = buckets.length - 1; i >= 0 && resultList.size() < k; i--) {
            if (!buckets[i].isEmpty()) {
                resultList.addAll(buckets[i]);
            }
        }

        System.out.println(resultList);

        // Convert the result list to an array
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = resultList.get(i);
        }

        return result;
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String args[]) {
        int arr[] = { 1, 1, 2, 2, 3, 4, 5, 6, 7, 7, 7 };

        int k = 2;
        int result[] = topKFrequent(arr, k);
        System.out.println("Top k = " + k + " elements in array :");
        printArray(result);

    }
}
