import java.util.ArrayList;
import java.util.Stack;

public class TopologicalSorting {
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

        graph[5].add(new Edge(5, 0));
        graph[5].add(new Edge(5, 2));

        graph[2].add(new Edge(2, 3));

        graph[3].add(new Edge(3, 1));

        graph[4].add(new Edge(4, 0));
        graph[4].add(new Edge(4, 1));
    }

    public static void topsort(ArrayList<Edge> graph[], boolean vis[], int curr, Stack<Integer> s) {
        vis[curr] = true;
        for (int i = 0; i < graph[curr].size(); i++) {
            Edge e = graph[curr].get(i);
            if (!vis[e.dest]) {
                topsort(graph, vis, e.dest, s);
            }
        }
        s.push(curr);
    }

    public static void main(String args[]) {
        int V = 6; // number of vertexes
        ArrayList<Edge> graph[] = new ArrayList[V];

        createGraph(graph);
        boolean vis[] = new boolean[V];
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < V; i++) {
            if (vis[i] == false) {
                topsort(graph, vis, i, s);
            }
        }

        // Print the topologically sorted order
        while (!s.isEmpty()) {
            System.out.print(s.pop() + " ");
        }
    }
}
