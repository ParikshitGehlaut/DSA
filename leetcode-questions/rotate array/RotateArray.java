public class RotateArray {
    public static void reverse(int arr[], int i, int j) {
        while (i < j) {
            arr[i] = arr[i] + arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
            i++;
            j--;
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 5 };
        int k = 72;
        int n = arr.length;
        reverse(arr, 0, n - (k % n) - 1);
        reverse(arr, n - (k % n), n - 1);
        reverse(arr, 0, n - 1);

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
