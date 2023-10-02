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
	srand(time(NULL));

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	n = 1e5; 
	m = 1e5; // 10^7
	int x = 1;

	cout << n << "\n";
	for (int i = 1; i <= n; i++) {
		int delta = 1 + rand() % 2;
		x += delta;
		cout << x << " ";
	}
	cout << "\n";
	cout << m;

	x = 1;
	for (int i = 1; i <= n; i++) {
		int delta = 1 + rand() % 2;
		x += delta;
		cout << x << " ";
	}
	cout << "\n";



	return 0;
}