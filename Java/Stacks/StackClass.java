package Stacks;

import java.util.ArrayList;

public class StackClass {
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
        }
    }

    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.print();
        System.out.println("Top element: " + stack.peek());
        System.out.println("Stack size: " + stack.size());
        System.out.println("Popped element: " + stack.pop());
        stack.print();
        System.out.println("Stack size after pop: " + stack.size());
    }
}