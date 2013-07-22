//Entrada: Un array
//Salida: El vector "array" ordenado
//        La cantidad optima de intercambios
int array[MAXN];
int temp[MAXN];
int intercambios = 0;
int d = 0;
void mergesort(int inicio, int length) {
	if(length<=1)
		return;
	mergesort(inicio, length/2);
	mergesort(inicio+length/2, length-length/2);
	int i = inicio;
	int j = inicio+length/2;
	int n = 0;
	while(i<inicio+length/2 && j<inicio+length)
		if(array[i]<array[j]) {
			temp[n++] = array[i++];
			intercambios+=d; //para contar los intercambios
		} else {
			temp[n++] = array[j++];
			d++;
		}
	while(i<inicio+length/2) {
		temp[n++] = array[i++];
		intercambios+=d;
	}
	while(j<inicio+length)
		temp[n++] = array[j++];
	memcpy(array+inicio, temp, length*sizeof(int));
}
