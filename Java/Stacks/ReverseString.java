package Stacks;

import java.util.Stack;

public class ReverseString {
    public static void reversestring(String s) {
        Stack<Character> stack = new Stack<>();

        int idx = 0;
        while (idx < s.length()) {
            stack.push(s.charAt(idx));
            idx++;
        }

        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) {
            result.append(stack.pop());
        }

        System.out.println(result);
    }

    public static void main(String[] args) {
        reversestring("Parikshit");
    }

}
