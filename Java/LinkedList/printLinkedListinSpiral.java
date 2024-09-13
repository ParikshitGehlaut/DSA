import java.util.*;

public class printLinkedListinSpiral{
    static class Node {
        int data;
        Node next;
    };

    public static void printInSpiralForm(Node head){
        ArrayList<Integer> list = new ArrayList<>();
        Node t = head;

        while(t != null){
            list.add(t.data);
            t = t.next;
        }

        int n = list.size();
        int mid = (n-1)/2;
        int left = mid, right = mid + 1;

        while(left >= 0 || right < n){
            if(left >= 0) System.out.print(list.get(left) + "->");
            if(right < n) System.out.print(list.get(right) + "->");
            left--;
            right++;
        }
        System.out.println("NULL");
    }
    public static void main(String args[])
    {
        int arr[] = { 1, 2, 3, 4, 5, 6 };
        int n = arr.length;
        Node root = arrayToList(arr, n);
 
        printInSpiralForm(root);
    }
 
    static Node insert(Node root, int item)
    {
        Node temp = new Node();
        Node ptr;
        temp.data = item;
        temp.next = null;
 
        if (root == null)
            root = temp;
        else {
            ptr = root;
            while (ptr.next != null)
                ptr = ptr.next;
            ptr.next = temp;
        }
        return root;
    }

    static void display(Node root)
    {
        while (root != null) {
            System.out.print(root.data + " ");
            root = root.next;
        }
    }
 
    static Node arrayToList(int arr[], int n)
    {
        Node root = null;
        for (int i = 0; i < n; i++)
            root = insert(root, arr[i]);
        return root;
    }
}