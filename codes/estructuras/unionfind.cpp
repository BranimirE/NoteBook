struct UnionFind{
  int p[MAX], r[MAX], setSize[MAX];
  int n, numSets;
  UnionFind(int _N){
    reset(_N);
  }
  void reset(int N){
    n = N;
    numSets = n;
    for(int i = 0; i <= n; i++){
      p[i] = i;
      r[i] = 0;
      setSize[i] = 1;
    }
  }
  int Find(int i){return (p[i] == i)?i:(p[i] = Find(p[i]));}
  bool sameComponent(int i, int j){return Find(i) == Find(j);}
  void Union(int i, int j){
    if(!sameComponent(i, j)){
      numSets--;
      int x = Find(i), y = Find(j);
      if(r[x] > r[y]){
        p[y] = x;
        setSize[x] += setSize[y];
      } else                   {
        p[x] = y;
        setSize[y] += setSize[x];
        if (r[x] == r[y]) r[y]++;
      }
    }
  }
  int numDisjointSets(){
    return numSets;
  }
  int sizeOfSet(int i){
    return setSize[Find(i)];
  }
};