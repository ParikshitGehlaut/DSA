import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);

        System.out.println(q);

        q.remove();
        System.out.println(q);

        q.poll();
        System.out.println(q.size());

        // peek operations in queue
        System.out.println(q.peek());
        System.out.println(q.element());

        System.out.println(q);

        while (!q.isEmpty()) {
            System.out.println(q.remove());
        }
    }
}