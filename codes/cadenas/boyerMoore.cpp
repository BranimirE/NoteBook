#include<iostream>
#include<cstring>

//encuentra todos los match de un patron en el texto

using namespace std;

int M,N;

//M tamaño del patron
//N tamaño del texto

void preBM(char P[], int bmNext[])
{
    for(int i = 0; i <= 255; i++)
        bmNext[i] = M;
    for(int i = 0; i < M; i++)
        bmNext[P[i]] = M - 1 - i ;
}

void Boyer_Moore(char T[], char P[])
{

    int i = M - 1;
    int j = M - 1;
    int bmNext[255];
    preBM(P,bmNext);
    while((i < N) && (j >= 0))
    {
        if(T[i] == P[j])
        {
            i--;
            j--;
        }
        else
        {
            i += bmNext[T[i]];
            j = M - 1;
        }
        if(j < 0)
        {
            cout<<"Match en: "<<(i + 1)<<endl;
            i += M + 1;
            j = M - 1;
        }
    }
}

int main()
{
    char texto[100];
    char patron[100];
    cin>>texto;
    cin>>patron;
    M=strlen(patron);
    N=strlen(texto);
    Boyer_Moore(texto,patron);
    return 0;
}
