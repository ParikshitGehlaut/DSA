import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class CycleDetection {
    public static class Edge {
        int src;
        int dest;

        public Edge(int s, int d) {
            this.src = s;
            this.dest = d;
        }
    }

    public static void createGraph(ArrayList<Edge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }

        // Adding edges to create a cycle
        graph[0].add(new Edge(0, 1));
        graph[1].add(new Edge(1, 2));
        // graph[2].add(new Edge(2, 0));

        // Adding some additional edges that do not form a cycle
        graph[3].add(new Edge(3, 4));
        graph[4].add(new Edge(4, 5));
    }

    public static boolean detect(ArrayList<Edge> graph[], boolean vis[], int curr, boolean rec[]) {
        vis[curr] = true;
        rec[curr] = true;

        for (int i = 0; i < graph[curr].size(); i++) {
            Edge e = graph[curr].get(i);

            if (rec[e.dest] == true) {
                return true;
            } else if (!vis[e.dest] && detect(graph, vis, e.dest, rec)) {
                return true;
            }
        }
        rec[curr] = false;
        return false;
    }

    public static void main(String args[]) {
        int V = 5; // number of vertexes
        ArrayList<Edge> graph[] = new ArrayList[V];

        createGraph(graph);

        boolean result = detect(graph, new boolean[V], 0, new boolean[V]);
        System.out.println(result);

    }
}
