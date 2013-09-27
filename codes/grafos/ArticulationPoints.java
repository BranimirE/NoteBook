import java.util.*;

public class ArticulationPoints {

  static int time;
  static List<Integer>[] grafo;
  static boolean[] vis;
  static int[] tin;
  static int[] dfsLow;
  static List<Integer> puntosArticulacion;

  static void dfs(int u, int p) {
    vis[u] = true;
    dfsLow[u] = tin[u] = time++;
    int child = 0;
    for (int v : grafo[u]) {
      if (v == p) {
        continue;
      }
      if (vis[v]) {
        dfsLow[u] = Math.min(dfsLow[u], tin[v]);
      } else {
        dfs(v, u);
        dfsLow[u] = Math.min(dfsLow[u], dfsLow[v]);
        if (dfsLow[v] >= tin[u] && p != -1) {
          puntosArticulacion.add(u);
        }
        ++child;
      }
    }
    if (p == -1 && child > 1) {
      puntosArticulacion.add(u);
    }
  }

  public static void main(String[] args) {
    time = 0;
    int n = 5;
    grafo = new List[n];
    for (int i = 0; i < n; i++) {
      grafo[i] = new ArrayList<>();
    }
   
    vis = new boolean[n];
    tin = new int[n];
    dfsLow = new int[n];
    puntosArticulacion = new ArrayList<>();

    dfs(0, -1);

    //System.out.println(puntosArticulacion); si puntosArticulacion == null entonces es un grafo biconexo
  }
}
