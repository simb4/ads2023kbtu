#include <iostream>

using namespace std;


/*
	10^8 operations = 1 sec

	O(n * m)
*/

const int N = (int)1e5 + 5;

int n, m;
int a[N];
int x[N];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	int cntNO = 0;
	int cntYES = 0;

	// i is the first pointer, iterates over
	// queries,
	// second pointer is j - iterates over an array, 
	// that point to first non-considered number
	int j = 1;

	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		
		while (j <= n && a[j] < x)
			j++;

		/*
			a[j] is the leftmost number
			that is >= x in a.
		*/
		if (a[j] == x) {
			// cout << "YES " << j << "\n";
			cntYES++;
		} else {
			// cout << "NO\n";
			cntNO++;
		}
	}
	cout << "NO = " << cntNO << "\n";
	cout << "YES = " << cntYES << "\n";


	return 0;
}