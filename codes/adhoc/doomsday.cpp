//Entrada: Una fecha (ene = 1, ..., dic = 12) Salida: Dia de la semana
string vec[7] = {"DOM","LUN","MAR","MIE","JUE","VIE","SAB"};

string doomsday(int dia, int mes, int anio){
	int a, y, m, d;	
	a = (14 - mes) / 12;
	y = anio - a;
	m = mes + 12 * a - 2;
	d = (dia + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
	return vec[d];
}