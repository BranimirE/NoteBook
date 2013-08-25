class Polinomio {
    double[] coef;

    // a0 + a1x + a2x^2 + ...
    public Polinomio(double[] coef) {
        this.coef = coef;
    }

    public double integrar(double a, double b) {
        Polinomio integ = integral();
        return integ.evaluar(b) - integ.evaluar(a);
    }

    public double evaluar(double x) {
        double result = 0;
        for (int i = coef.length - 1; i >= 0; i--)
            result = coef[i] + x*result;
        return result;
    }

    public Polinomio integral() {
        double[] newCoef = new double[coef.length + 1];
        newCoef[0] = 0;
        for (int i = 1; i < newCoef.length; i++)
            newCoef[i] = coef[i-1]/i;
        return new Polinomio(newCoef);
    }

    public Polinomio cuadrado() {
        double[] newCoef = new double[coef.length * 2 - 1];
        for (int i = 0; i < newCoef.length; i++)
            for (int j = 0; j <= i; j++)
                if (j < coef.length && i - j < coef.length)
                    newCoef[i] += coef[j] * coef[i-j];

        return new Polinomio(newCoef);
    }

    public Polinomio multiplicar(double c) {
        double[] newCoef = new double[coef.length];
        for (int i = 0; i < newCoef.length; i++)
            newCoef[i] = coef[i] * c;
        return new Polinomio(newCoef);
    }
}
