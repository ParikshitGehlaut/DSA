import java.util.Scanner;

public class RepeatingNumber {

    public static int repeatingNumber(int[] arr) {
        int n = arr.length;
        int result = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    result = arr[i];
                }
            }
        }

        return result;
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

        int result = repeatingNumber(arr);
        System.out.println("result is: " + result);

    }
}