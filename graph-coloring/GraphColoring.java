import java.util.Scanner;

public class GraphColoring {
    static int n;
    static int m;
    static boolean[][] graph;
    static int[] colors;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        n = scanner.nextInt();
        System.out.print("Enter the number of colors: ");
        m = scanner.nextInt();

        graph = new boolean[n][n];
        System.out.println("Enter the adjacency matrix of the graph (0 for false, 1 for true):");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = scanner.nextInt() == 1;
            }
        }

        colors = new int[n];

        if (mColoring(0)) {
            for (int i = 0; i < n; i++) {
                System.out.println("Vertex " + (i + 1) + ": Color " + colors[i]);
            }
        } else {
            System.out.println("Graph cannot be colored with " + m + " colors.");
        }

        scanner.close();
    }

    static boolean mColoring(int k) {
        if (k == n) {
            return true;
        }

        for (int color = 1; color <= m; color++) {
            if (isLegalColor(k, color)) {
                colors[k] = color;
                if (mColoring(k + 1)) {
                    return true;
                }
                colors[k] = 0; // Backtrack
            }
        }
        return false;
    }

    static boolean isLegalColor(int vertex, int color) {
        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] && colors[i] == color) {
                return false;
            }
        }
        return true;
    }
}
