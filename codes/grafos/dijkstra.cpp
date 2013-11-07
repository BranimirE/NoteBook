	for(int i = 0; i < nodos; ++i){
		d[i] = INF;
		v[i] = false;
	}
	d[ini] = 0;
	q.insert(make_pair(0,ini));
	while(!q.empty()){
		act = (*(q.begin())).second;q.erase(q.begin());
		if(v[act])continue;
		v[act] = true;
		for(int i = 0; i < grafo[act].size(); ++i){
			ady = grafo[act][i].first;
			peso = grafo[act][i].second;
			if(!v[ady] && d[act] + peso < d[ady] ){
				d[ady] = d[act] + peso;
				q.insert(make_pair(d[ady],ady));
			}
		}			
	}
	if(d[fin] != INF) cout << d[fin] << endl;
	else cout << "unreachable" << endl;