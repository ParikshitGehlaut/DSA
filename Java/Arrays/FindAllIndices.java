import java.util.ArrayList;

public class FindAllIndices {
    public static ArrayList<Integer> allIndices(int[] arr, int n, int target, int idx) {
        // base case
        if (idx >= n) {
            return new ArrayList<Integer>();
        }
        ArrayList<Integer> ans = new ArrayList<Integer>();

        if (arr[idx] == target) {
            ans.add(idx);
        }
        ArrayList<Integer> smallAns = allIndices(arr, n, target, idx + 1);
        ans.addAll(smallAns);
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = { 8, 8, 8 };
        ArrayList<Integer> result = allIndices(arr, 3, 8, 0);
        for (Integer i : result) {
            System.out.print(i + " ");
        }
    }
}
