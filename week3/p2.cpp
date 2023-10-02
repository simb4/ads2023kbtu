#include <iostream>

using namespace std;


/*
	10^8 operations = 1 sec

	O(m * log(n) + n)
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
	for (int j = 1; j <= m; j++) {
		int x;
		cin >> x;
		/* 
			do binary search 
		*/
		int l = 1, r = n; // search range
		int p = 0;
		while (l < r) {
			int mid = (l + r) / 2;
			if (x == a[mid]) {
				l = mid;
				break;
			} else if (x < a[mid])
			// [l,r] -> [l,mid-1]
				r = mid - 1;
			else { // a[mid] < x
				l = mid + 1;
			}
		}
		/*
			we reach here if:
			either we break while loop
			or it completed and l == r
		*/
		if (a[l] == x) {
			cout << "YES " << l << "\n";
			cntYES++;
		} else {
			cout << "NO\n";
			cntNO++;
		}
	}
	cout << "NO = " << cntNO << "\n";
	cout << "YES = " << cntYES << "\n";


	return 0;
}