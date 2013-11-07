#define MAXN 600005
char str[MAXN];
int rad[MAXN];
int n;
/*
En rad se guarda el tamanio del palindromo
str[0]='$';         // si o si 
scanf("%s", str+1); // puntero para iniciar desde 1
n=strlen(str+1);
*/
void Manacher() {
    int i, j, k;
    i = 1;
    j = 0;
    while (i <= n) {
        while (str[i - j] == str[i + j + 1] && i - j > 0 && i + j + 1 <= n) j++;
        rad[i] = j;
        k = 1;
        while (k <= rad[i] && rad[i - k] != rad[i] - k) {
            rad[i + k] = min(rad[i - k], rad[i] - k);
            k++;
        }
        i = i + k;
        j = max(j - k, 0);
    }
}
