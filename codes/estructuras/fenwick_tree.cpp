#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

#define ll long long

using namespace std;

const int maxn=10000000;
int tree[maxn];
vector<int> v;

void add(int i,int k){
  for(; i < maxn; i += i&-i ) tree[i] += k;
}

ll get(ll i){
  ll s = 0;
  for(; i > 0; i-=i&-i) s+=tree[i];
  return s;
}

int main(){
  memset( tree,0,sizeof tree );
  for( int j = 0; j < n; ++j ){
      cin >> num;
      v.push_back(num);
  }
  for( int j = v.size()-1; j > -1; --j ){
      add(v[j],1);
      ans += get(v[j]-1); 
  }
  //ans respuesta 
  return 0;
}
