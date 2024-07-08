import java.util.*;

public class EqualSumSubArray {
    public static void printarray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static boolean check_for_equal_subarray(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            arr[i] = arr[i - 1] + arr[i];
        }
        int totalsum = arr[arr.length - 1];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == totalsum - arr[i]) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter " + n + " elements");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        printarray(arr);
        boolean result = check_for_equal_subarray(arr);
        System.out.println("result is: " + result);
    }
}
