import java.util.*;

public class Bridges {

  static int time;
  static List<Integer>[] graph;
  static boolean[] used;
  static int[] tin;
  static int[] lowlink;
  static List<String> bridges;

  static void dfs(int u, int p) {
    used[u] = true;
    lowlink[u] = tin[u] = time++;
    for (int v : graph[u]) {
      if (v == p) {
        continue;
      }
      if (used[v]) {
        // lowlink[u] = Math.min(lowlink[u], lowlink[v]);
        lowlink[u] = Math.min(lowlink[u], tin[v]);
      } else {
        dfs(v, u);
        lowlink[u] = Math.min(lowlink[u], lowlink[v]);
        if (lowlink[v] > tin[u] && p != -1) {
          bridges.add("(" + u + "," + v + ")");
        }
      }
    }
  }
  public static void main(String[] args) {
    time = 0;
    int n = 6;
    graph = new List[n];
    for (int i = 0; i < n; i++) {
      graph[i] = new ArrayList<>();
    }
    used = new boolean[n];
    tin = new int[n];
    lowlink = new int[n];
    bridges = new ArrayList<>();

    dfs(0, -1);

    System.out.println(bridges);
  }
}
