public class LinearSearch {
    public static boolean search(int[] arr, int target, int idx) {
        if (arr[idx] == target) {
            return true;
        }
        if (idx == arr.length - 1) {
            return false;
        }
        return search(arr, target, idx + 1);

    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5 };
        boolean result = search(arr, 5, 0);
        System.out.println(result);
    }
}
