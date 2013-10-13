vector<int> g[MAX];
int color[MAX];
int bipartiteCheck(int ini) {
  queue<int> q;
  q.push(ini);
  color[ini] = 0;
  int visitados = 1, negros = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int j = 0; j < g[u].size(); j++) {
      int v = g[u][j];
      if(color[v] == INF) {
        visitados++;
        color[v] = 1 - color[u];
        if(color[v])negros++;
        q.push(v);
      } else if(color[v] == color[u])
        return -1;
    }
  }
  if(visitados == 1) return 1;// si solo es una esquina si o si es necesario un guardia
  return min(negros, visitados - negros);
}

int colorear() {
  memset(color, -1, sizeof(color));
  int ans = 0;
  for(int i = 0; i < n; i++)//ID de nodos van de 0 a n-1
    if(color[i] == -1) {
      int tmp = bipartiteCheck(i);
      if(tmp == -1)return -1;//no se puede bicolorear
      ans += tmp;
    }
  return ans;
}