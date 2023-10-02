#include <iostream>

using namespace std;


/*
	10^8 operations = 1 sec
	n <= 10^5
	m <= 10^5
	O(n * m)
*/

const int N = (int)1e5 + 5;

int n, m;
int a[N];

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
	for (int j = 1; j <= m; j++) {
		int x;
		cin >> x;
		/* do linear search */
		int p = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] == x) {
				p = i;
				break;
			}
		if (p == 0) {
			cntNO++;
			cout << "NO\n";
		}
		else {
			cntYES++;
			cout << "YES " << p << "\n";
		}
	}
	cout << "NO = " << cntNO << "\n";
	cout << "YES = " << cntYES << "\n";


	return 0;
}