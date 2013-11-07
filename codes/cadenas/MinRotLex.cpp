/*
Rotacion Lexicografica minima MinRotLex(cadena,tamaño)
para cambiar inicio de la cadena char s[300]; int h; s+h; 
retorna inicio de la rotacion minima :D
*/
int MinRotLex(const char *s, const int slen) {
  //for(int j=0;j<slen;j++){
  //    cout<<s[j];      
  // }
   int i = 0, j = 1, k = 0, x, y, tmp;
   while(i < slen && j < slen && k < slen) {
      x = i + k;
      y = j + k;
      if(x >= slen)  x -= slen;
      if(y >= slen)  y -= slen;
      if(s[x] == s[y]) {
         k++;
      } else if(s[x] > s[y]) {
         i = j+1 > i+k+1 ? j+1 : i+k+1;
         k = 0;
         tmp = i, i = j, j = tmp;
      } else {
         j = i+1 > j+k+1 ? i+1 : j+k+1;
         k = 0;
      }
   }
   return i;
}
