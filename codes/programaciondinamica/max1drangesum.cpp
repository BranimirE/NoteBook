//Algoritmo de kadane
//Entrada: Un vector de numero enteros
//Salida : La suma maxima de alguno de rangos en O(n)
long long int maxrangesum(vector<int> &v) {
  long long int sum = 0, ans = -(1LL<<60);//la maxima suma podria ser negativa
  for(int i = 0; i < v.size(); i++) {
    sum += v[i];
    ans = max(ans, sum);
    if(sum < 0) sum = 0;
  }
  return ans;
}