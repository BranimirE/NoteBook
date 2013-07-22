#include <vector>
#include <bitset>

#define MAXPRIME 3162300 // raiz de maximo numero que manejaremos

using namespace std;

bitset<MAXPRIME> criba;
vector<long long int> primos;

void llena_criba()
{
	criba.set();// marcamos todo como false
	for (int i = 2; i < MAXPRIME; i++)
		if (criba.test( i ))
		{
			primos.push_back( i );
			for (int j= i + i; j<MAXPRIME; j += i)
				criba.reset( j );
		}
}
