struct nodo{
	int valor;
	nodo* izq;
	nodo* der;
	nodo(){
		valor = (1<<30);
		izq = NULL;
		der = NULL;
	}
	nodo(int _v){
		valor = _v;
		izq = NULL;
		der = NULL;
	}
};

void insertar(int val, nodo **n){
	if((*n) == NULL)
		*n = new nodo(val);
	else
		if(val > (*n)->valor)
			insertar(val, &((*n)->der));
		else
			insertar(val, &((*n)->izq));
}

void inorden(nodo *n){
	if(n != NULL){
		inorden(n->izq);
		cout << (n->valor) <<" ";
		inorden(n->der);
	}
}
int main(){
	nodo *raiz;
	raiz = NULL;
	int nro,tmp;
	cin >> nro;
	while(nro--){
		cin >> tmp;
		insertar(tmp, &raiz);
	}
	cout << "IN-ORDEN" << endl;
	inorden(raiz);
	return 0; 
}