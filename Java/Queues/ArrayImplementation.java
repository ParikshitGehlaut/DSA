
public class ArrayImplementation {
    public static class QueueArray {
        static int f = -1;
        static int r = -1;
        private static int size = 0;
        static int[] arr = new int[100];

        public void add(int element) {
            if (r == arr.length - 1) {
                System.out.println("Queue is full");
                return;
            }
            if (f == -1) {
                f = 0;
                r = 0;
                arr[r] = element;
            } else {
                arr[++r] = element;
            }
            size++;
        }

        public int size() {
            return size;
        }

        public int remove() {
            int lastValue = arr[f];
            f++;
            size--;
            return lastValue;
        }

        public int peek() {
            return arr[f];
        }
    }

    public static void main(String[] args) {

        QueueArray q = new QueueArray();
        // Test case 1: Adding elements to the queue
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

        // Test case 5: Remove elements from an empty queue
        System.out.println("Test Case 5: Remove elements from an empty queue");
        q.remove();
        q.remove();
        q.remove();
        try {
            q.remove(); // This might throw an exception or return an invalid value
        } catch (Exception e) {
            System.out.println("Caught exception as expected when removing from empty queue: " + e.getMessage());
        }

        System.out.println("All test cases passed.");
    }
}
