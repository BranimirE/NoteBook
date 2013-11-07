#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <list>
#include <set>
#include <map>
using namespace std;
#define MAXN 1000005
int n,t;  //n es el tamanio de la cadena
int m,tam1;
set<string> orde;
int p[MAXN],r[MAXN],h[MAXN];
//r indices del sa para mostrar indice   s.substr(r[i])
//p es el inverso del suffix array, no usa indices del suffix array ordenado
//h el el tamanio del lcp entre el i-esimo y el i+1-esimo elemento de suffix array ordenado
char s[250000];
char s2[250000];
void fix_index(int *b, int *e) {
   int pkm1, pk, np, i, d, m;
   pkm1 = p[*b + t];
   m = e - b; d = 0;
   np = b - r;
   for(i = 0; i < m; i++) {
      if (((pk = p[*b+t]) != pkm1) && !(np <= pkm1 && pk < np+m)) {
         pkm1 = pk;
         d = i;
      }
      p[*(b++)] = np + d;
   }
}
 
bool comp(int i, int j) {
   return p[i + t] < p[j + t];
}
void suff_arr() {
   int i, j, bc[256];
   t = 1;
   for(i = 0; i < 256; i++) bc[i] = 0;  //alfabeto
   for(i = 0; i < n; i++) ++bc[int(s[i])]; //counting sort inicial del alfabeto
   for(i = 1; i < 256; i++) bc[i] += bc[i - 1];
   for(i = 0; i < n; i++) r[--bc[int(s[i])]] = i;
   for(i = n - 1; i >= 0; i--) p[i] = bc[int(s[i])];
   for(t = 1; t < n; t *= 2) {
      for(i = 0, j = 1; i < n; i = j++) {
         while(j < n && p[r[j]] == p[r[i]]) ++j;
         if (j - i > 1) {
            sort(r + i, r + j, comp);
            fix_index(r + i, r + j);
         }
      }
   }
}
 
void lcp() {
   int tam = 0, i, j;
   for(i = 0; i < n; i++)if (p[i] > 0) {
      j = r[p[i] - 1];
      while(s[i + tam] == s[j + tam]) ++tam;
      h[p[i] - 1] = tam;
      if (tam > 0) --tam;
   }
   h[n - 1] = 0;
}
int owner(int idx){
    return (idx < n-m-1) ? 1 : 2;
}
int main(){
   freopen("760.in","r",stdin);
   bool sw=false;
   while(scanf("%s",&s)==1){
      scanf("%s",&s2);
      strcat(s,"$");
      tam1=strlen(s);
      strcat(s,s2);
      strcat(s,"#");
      n =strlen(s);
      m=strlen(s)-tam1;
      suff_arr();
      lcp();
      int dev=0;
      string dev2;
      orde.clear();
      for(int i=0;i<n;i++){
         if(owner(r[i]) != owner(r[i-1])){   //por si quiere mostrat $ o #
            if(h[i-1] >= dev){
               dev=h[i-1];
               //cout<<r[i]<<" --- "<<h[i-1]<<endl;
               string aux="",aux2="";
               for(int j=0;j<dev;j++){ 
                  aux2=s[r[i]+j];
                  aux+=aux2;
               }
               orde.insert(aux);
            }
         }
      }

      if(sw)
         printf("\n");
      sw = true;
      if(dev == 0)
         printf("No common sequence.\n");
      else{
         set<string>::iterator it=orde.begin();
         for (;it!=orde.end(); it++){
          if((*it).size()==dev)cout <<*it<< endl;
       }
    }
 }
 return 0;
}

 //rotacion menor lexicografica
 /*
 int tam1=strlen(s);
      for(int i=tam1;i<2*tam1;i++)s[i]=s[i-tam1];
      n=2*tam1;
      suff_arr();
      char dev[tam1];
      for(int i=0;i<n;i++)
         if(r[i]<tam1){
            for(int j=r[i];j<r[i]+tam1;j++)
               dev[j-r[i]]=s[j];
            break;
         }
      for(int i=0;i<tam1;i++)
      printf("%c",dev[i]);
      
 */
/*
ACM 2009 File Recover   Solucion  
Problema: Contar los substrings q se repiten al menos una vez.
Analisis: Notamos que si el lcp(i,i+1) con lcp(i+1,i+2)  aumenta 
quiere decir que encontramos h[i+1]-h[i] palabras nuevas (prefijos)
SUM(max(h[i+1]-h[i],0))
*/
