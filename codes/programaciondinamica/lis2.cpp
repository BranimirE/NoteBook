#include <stdio.h>
#define SIZE 200000
#define MAX(x,y) ((x)>(y)?(x):(y))

int best[SIZE];        // best[] holds values of the optimal sub-sequence

int main (void) {
	int i, n, k, x, sol;
	int low, high;

	scanf ("%d", &n);	// N = how many integers to read in
	// read in the first integer
	scanf ("%d", &best[0]);
	sol = 1;
	for (i = 1; i < n; i++) {
		best[i] = -1;
		scanf ("%d", &x);

		if(x >= best[0]) {
			k = 0;
			best[0] = x;
		}
		else {
			// use binary search instead
			low = 0;
			high = sol-1;
			for(;;) {
				k = (int) (low + high) / 2;
				// go lower in the array
				if(x > best[k] && x > best[k-1]) {
					high = k - 1;
					continue;
				}
				// go higher in the array
				if(x < best[k] && x < best[k+1]) {
					low = k + 1;
					continue;
				}
				// check if right spot
				if(x > best[k] && x < best[k-1])
					best[k] = x;
				if(x < best[k] && x > best[k+1])
					best[++k] = x;
				break;
			}
		}
		sol = MAX (sol, k + 1);
	}
	printf ("best is %d\n", sol);
	return 0;
}