public class IsSorted {
    public static boolean sort(int[] arr, int n, int idx) {
        if (idx == n - 1) {
            return true;
        }
        if (arr[idx] > arr[idx + 1]) {
            return false;
        }
        return sort(arr, n, idx + 1);
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 4, 4, 3, 5 };
        boolean result = sort(arr, 5, 0);
        System.out.println(result);
    }
}
