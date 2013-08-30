#include <vector>
#include <iostream>
#include <stack>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector < vector<char> > a (n, vector<char> (m));
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> a[i][j];

	int ans = 0;
	vector<int> d (m, -1);
	vector<int> dl (m), dr (m);
	stack<int> st;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j)
			if (a[i][j] == 1)
				d[j] = i;
		while (!st.empty()) st.pop();
		for (int j=0; j<m; ++j) {
			while (!st.empty() && d[st.top()] <= d[j]) st.pop();
			dl[j] = st.empty() ? -1 : st.top();
			st.push (j);

		}
		while (!st.empty()) st.pop();
		for (int j=m-1; j>=0; --j) {
			while (!st.empty() && d[st.top()] <= d[j]) st.pop();
			dr[j] = st.empty() ? m : st.top();
			st.push (j);
		}
		for (int j=0; j<m; ++j)
			ans = max (ans, (i - d[j]) * (dr[j] - dl[j] - 1));
	}
	cout << ans;
	return 0;
}
