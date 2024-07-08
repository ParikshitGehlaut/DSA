package Stacks;

import java.util.ArrayList;

public class ReverseStack {
    public static class Stack {
        ArrayList<Integer> stack = new ArrayList<>();

        public boolean isEmpty() {
            return stack.size() == 0;
        }

        public int size() {
            return stack.size();
        }

        public void push(int val) {
            stack.add(val);
        }

        public int pop() {
            if (!isEmpty()) {
                return stack.remove(stack.size() - 1);
            } else {
                return -1;
            }
        }

        public int peek() {
            if (!isEmpty()) {
                return stack.get(stack.size() - 1);
            } else {
                return -1;
            }
        }

        public void print() {
            if (!isEmpty()) {
                for (int i = stack.size() - 1; i >= 0; i--) {
                    System.out.print(stack.get(i) + " ");
                }
            } else {
                System.out.println("stack is Empty!");
            }
            System.out.println();
        }
    }

    public static void insertAtBottom(Stack s, int topElement) {
        // Base case
        if (s.isEmpty()) {
            s.push(topElement);
            return;
        }
        int data = s.pop();
        insertAtBottom(s, topElement);
        s.push(data);
    }

    public static void reverse(Stack s) {
        // base case
        if (s.isEmpty()) {
            return;
        }
        int topElement = s.pop();
        reverse(s); // recursion part, we are assuming that through recursion, wel will get stack
                    // that is already reversed and we add top element at the bottom of stack
        insertAtBottom(s, topElement);
    }

    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.print();
        reverse(stack);
        stack.print();

    }
}
