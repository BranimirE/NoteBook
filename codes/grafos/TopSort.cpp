using namespace std;
vector<int>graph[110];
bool visitado[110];
vector<int> sol;
int n,m;
void dfs(int node) {
	visitado[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		if (!visitado[graph[node][i]])
			dfs(graph[node][i]);
	}
	sol.push_back(node);
}
void lim(){
	for(int i=0;i<=110;i++)
		graph[i].clear();

	clr(visitado);
	sol.clear();
}
int main() {
    //llenado 
		for (int i = 1; i <= n; i++)
			if(!visitado[i])dfs(i);
		reverse(sol.begin(), sol.end());
		//printsol
	return 0;
}