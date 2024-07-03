public class reverseLL_using_iteration {
    public static class Node {
        int val;
        Node next;

        Node(int val) {
            this.val = val;
        }
    }

    public static Node reverse(Node head) {
        Node curr = head;// current pointer
        Node nex = null; // next pointer
        Node prev = null; // previous pointer

        while (curr != null) {
            nex = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }

    public static void displayLL(Node head) {
        if (head == null)
            return;
        System.out.print(head.val + " ");
        displayLL(head.next);
    }

    public static void main(String[] args) {
        Node a = new Node(3);
        Node b = new Node(5);
        Node c = new Node(1);
        Node d = new Node(2);
        Node e = new Node(4);

        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        e.next = null;

        displayLL(a);
        System.out.println();
        Node r = reverse(a);
        displayLL(r);

    }
}
