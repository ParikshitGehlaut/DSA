public class CircularQueueUsingArray {
    public static class CircularQueue {
        private int f;
        private int r;
        private int size;
        private int capacity;
        private int[] queue;

        public CircularQueue(int capacity) {
            this.capacity = capacity;
            this.f = this.r = -1;
            this.queue = new int[capacity];
            this.size = 0;
        }

        public boolean isFull() {
            return this.size == this.capacity;
        }

        public boolean isEmpty() {
            return this.size == 0;
        }

        public int size() {
            return this.size;
        }

        public void add(int element) {
            if (isFull()) {
                throw new IllegalStateException("Queue is Full");
            } else {
                if (this.f == -1) {
                    this.f = this.r = 0;
                } else {
                    this.r = (this.r + 1) % this.capacity;
                }
                queue[this.r] = element;
                this.size++;
            }
        }

        public int remove() {
            if (isEmpty()) {
                throw new IllegalStateException("Queue is empty");
            }
            int element = queue[this.f];
            this.f = (this.f + 1) % this.capacity;
            size--;
            return element;
        }

        public int peek() {
            if (isEmpty()) {
                throw new IllegalStateException("Queue is empty");
            }
            return queue[this.f];
        }
    }

    public static void main(String[] args) {
        CircularQueue q = new CircularQueue(5);

        System.out.println("Test Case 1: Enqueue elements to the queue");
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);
        assert q.size() == 5 : "Size should be 5 after enqueuing five elements.";
        assert q.peek() == 1 : "Front element should be 1.";

        System.out.println("Test Case 2: Dequeue elements from the queue");
        int removedElement1 = q.remove();
        int removedElement2 = q.remove();
        assert removedElement1 == 1 : "Removed element should be 1.";
        assert removedElement2 == 2 : "Removed element should be 2.";
        assert q.size() == 3 : "Size should be 3 after dequeuing two elements.";
        assert q.peek() == 3 : "Front element should be 3.";

        System.out.println("Test Case 3: Enqueue more elements to the queue");
        q.add(6);
        q.add(7);
        assert q.size() == 5 : "Size should be 5 after enqueuing five elements.";
        assert q.peek() == 3 : "Front element should be 3.";

        System.out.println("Test Case 4: Overflow condition");
        try {
            q.add(8); // This should throw an exception
        } catch (Exception e) {
            assert e instanceof IllegalStateException : "Expected IllegalStateException for enqueue on full queue";
            System.out.println("Caught exception as expected when enqueueing on full queue: " + e.getMessage());
        }

        System.out.println("Test Case 5: Dequeue all elements from the queue");
        q.remove();
        q.remove();
        q.remove();
        q.remove();
        assert q.size() == 0 : "Size should be 0 after dequeuing all elements.";

        System.out.println("Test Case 6: Underflow condition");
        try {
            q.remove(); // This should throw an exception
        } catch (Exception e) {
            assert e instanceof IllegalStateException : "Expected IllegalStateException for dequeue on empty queue";
            System.out.println("Caught exception as expected when dequeueing on empty queue: " + e.getMessage());
        }

        System.out.println("All test cases passed.");
    }
}
