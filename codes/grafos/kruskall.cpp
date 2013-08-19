#define lim 100000
using namespace std;
typedef vector<pair<int,pair<int,int> > > V;
int N,lider[lim];
V v;
void init(){
	Sort(v);
	for(int i=0;i<N;i++)lider[i]=i;
}
int find(int n){
	if(n==lider[n])return n;
	else return lider[n]=find(lider[n]);
}
int kruskall(){
	int a,b,sum=0;
	init();
	for(int i=0;(int)i<v.sz;i++){
		a=find(v[i].s.f);
		b=find(v[i].s.s);
		if(a!=b){
			lider[b]=a;
			sum+=v[i].f;
		}
	}
	return sum;
}
//v.pb(mp(c,mp(a,b))); peso(c),arista(a,b)
