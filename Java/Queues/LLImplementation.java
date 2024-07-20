public class LLImplementation {
    public class Node {
        int val;
        Node next;

        public Node(int val) {
            this.val = val;
        }
    }

    public class QueueLL {
        private Node f, r; // f -> front, r -> rear
        private int size; // size of queue

        public QueueLL() {
            this.f = this.r = null;
            this.size = 0;
        }

        public int size() {
            return this.size;
        }

        public void add(int element) {
            if (size() == 0) {
                Node newNode = new Node(element);
                this.f = this.r = newNode;
            } else {
                Node newNode = new Node(element);
                this.r.next = newNode;
                this.r = this.r.next;
            }
            size++;
        }

        public int remove() {
            if (this.f == null) {
                throw new IllegalStateException("Queue is empty");
            }
            int lastValue = this.f.val;
            this.f = this.f.next;
            size--;
            if (this.f == null) {
                this.r = null;
            }
            return lastValue;
        }

        public int peek() {
            if (this.f == null) {
                throw new IllegalStateException("Queue is empty");
            }
            return this.f.val;
        }
    }

    public static void main(String[] args) {
        LLImplementation llImplementation = new LLImplementation();
        QueueLL q = llImplementation.new QueueLL();

        System.out.println("Test Case 1: Adding elements to the queue");
        q.add(1);
        q.add(2);
        q.add(3);
        assert q.size() == 3 : "Size should be 3 after adding three elements.";
        assert q.peek() == 1 : "Peek should return the first element added, which is 1.";

        // Test case 2: Removing elements from the queue
        System.out.println("Test Case 2: Removing elements from the queue");
        int removedElement1 = q.remove();
        assert removedElement1 == 1 : "Removed element should be 1.";
        assert q.size() == 2 : "Size should be 2 after removing one element.";
        assert q.peek() == 2 : "Peek should return the next element, which is 2.";

        // Test case 3: Removing all elements from the queue
        System.out.println("Test Case 3: Removing all elements from the queue");
        int removedElement2 = q.remove();
        int removedElement3 = q.remove();
        assert removedElement2 == 2 : "Removed element should be 2.";
        assert removedElement3 == 3 : "Removed element should be 3.";
        assert q.size() == 0 : "Size should be 0 after removing all elements.";

        // Test case 4: Peek operation
        System.out.println("Test Case 4: Peek operation");
        assert q.peek() == 1 : "Peek should return the first element, which is 1.";

        System.out.println("All test cases passed.");
    }
}
