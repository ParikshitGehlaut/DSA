// package Stacks;

import java.util.*;

public class RemoveConsecutiveSubsequences {
    public static int[] remove(int[] arr) {
        int n = arr.length;
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {
            if (st.isEmpty() || st.peek() != arr[i]) {
                st.push(arr[i]);
            } else {
                while (i < n && arr[i] == st.peek()) {
                    i++;
                }
                st.pop();
                i--; // Adjust i because the for loop will increment it again
            }
        }

        int[] result = new int[st.size()];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = st.pop();
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 2, 3, 10, 10, 10, 4, 4, 4, 5, 7, 7, 2 };
        int[] result = remove(arr);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}
