public class reverseLL {
    public static class Node {
        int val;
        Node next;

        Node(int val) {
            this.val = val;
        }
    }

    public static Node reverse(Node head) {
        // Base case
        if (head.next == null)
            return head;

        Node newhead = reverse(head.next);
        head.next.next = head; // 1 -> 2 ->null changes to 1 <=> 2
        head.next = null; // 1 <=> 2 changes to null <- 1 <- 2
        return newhead;
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