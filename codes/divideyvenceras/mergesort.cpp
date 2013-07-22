//Entrada: p = indice del primer elemento a ordenar
//         r = indice del ultimo elemento a ordenar
//Salida: El vector "a" ordenado
int a[LIM], L[LIM/2 + 4], R[LIM/2 + 4];
void fusionar(long p,long q,long r) {
	long i,j,k,ind1,ind2;
	ind1 = ind2 = 1;
	for(i = p; i <= q; i++)
		L[ind1++] = a[i];
	L[ind1] = inf;
	for(i = q+1; i <= r; i++)
		R[ind2++] = a[i];
	R[ind2] = inf;
	i = j = 1;
	for(k = p; k <= r; k++)
		if(L[i] > R[j]) {
			a[k] = R[j];
			j++;
		} else {
			a[k] = L[i];
			i++;
		}
}
void mergeSort(long p,long r) {
	if(p < r) {
		long q = (p+r)/2;
		mergeSort(p,q);
		mergeSort(q+1,r);
		fusionar(p,q,r);
	}
}
