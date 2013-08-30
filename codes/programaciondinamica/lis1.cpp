#include <stdio.h>
#define SIZE 200000
#define MAX(x,y) ((x)>(y)?(x):(y))

int best[SIZE];        // best[] holds values of the optimal sub-sequence

int main (void) {
	int i, n, k, x, sol = -1;
	scanf ("%d", &n);	// N = how many integers to read in
	for (i = 0; i < n; i++) {
		best[i] = -1;
		scanf ("%d", &x);
		for (k = 0; best[k] > x; k++)
			;
		best[k] = x;
		sol = MAX (sol, k + 1);
	}
	printf ("best is %d\n", sol);
	return 0;
}
