  vector<int> dist(n, INF); dist[S] = 0;
  queue<int> q; q.push(S);
  vector<int> in_queue(n, 0); in_queue[S] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop(); in_queue[u] = 0;
    for (j = 0; j < (int)AdjList[u].size(); j++) {
      int v = AdjList[u][j].first, weight_u_v = AdjList[u][j].second;
      if (dist[u] + weight_u_v < dist[v]) {
        dist[v] = dist[u] + weight_u_v;
        if (!in_queue[v]) { //Agregamos a la cola solo si no esta en la cola
          q.push(v);
            in_queue[v] = 1;
        }
      }
    }
  }
  if (dist[T] != INF) printf("%d\n", dist[T]);
  else                printf("unreachable\n");