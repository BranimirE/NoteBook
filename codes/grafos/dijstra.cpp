#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;

typedef int V;			//tipo coste
typedef pair<V,int> P; 	//(coste,nodo)
typedef set<P> S;		
int N;
vector<P>A[10001];		//COSTE NODO
V dijstra(int s, int t){
	S m;
	vector<V>z(N,1000000000);
	z[s]=0;
	m.insert(mp(0,s));
	while(m.size() > 0){	
		P p=*m.begin();
		m.erase(m.begin());
		if(p.s==t)return p.f;
		for(int i=0 ;i<A[p.s].size();i++){
			P q(p.f + A[p.s][i].f, A[p.s][i].s);
			if(q.f < z[q.s]){
				m.erase(mp(z[q.s],q.s));
				m.insert(q);
				z[q.s]=q.f;
			}
		}
	}
	return -1; 
}
int main(){
	N=6;
	//llenado
	//A[a].pb(mp(c,b)); arista a,b coste c
	A[0].pb(mp(2,1));//arista(0,1) coste 2
	//solucion
	printf("%d\n",dijstra(4,5));
	return 0;
}
