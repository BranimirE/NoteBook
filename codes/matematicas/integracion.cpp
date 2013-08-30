double a[12];

int n;

double f(double x){
	double ans = 0;
	for(int i = 0; i <= n; i++)
		ans += (a[i] * pow(x,i));
	return ans*ans*PI;
}
double S(double a, double b, double c, double h){
	return (h / 3.0) * ( f(a) + 4.0 * f(c) + f(b));
}
double SIMP(double a, double b, double E ){
	double h = (b-a)/2.0,
	       c = (b+a)/2.0;

	double a1 = a,  b1 = c,
	       a2 = c,  b2 = b;

	double c1 = (b1+a1)/2.0, 
	       c2 = (b2+a2)/2.0;

	double L = (S(a1,b1, c1,h) + S(a2,b2,c2,h)) / 2.0;
	if(0.1*abs(L-S(a,b,c,h)) < E)
		return L;
	else
		return SIMP(a1,b1, E/2.0) + SIMP(a2,b2, E/2.0);
}
