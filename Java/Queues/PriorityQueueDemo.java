import java.util.*;

public class PriorityQueueDemo {
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        pq.add(3);
        pq.add(1);
        pq.add(5);
        pq.add(6);

        System.out.println(pq);
        System.out.println(pq.poll());
        System.out.println(pq);
    }
}
