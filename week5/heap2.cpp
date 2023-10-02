#include <iostream>

using namespace std;

const int N = (int)1e5 + 5;

int n; // size of heap
int a[N]; // storage


void heapify_up(int v) {
	// until I didn't reach root
	// and parent's value is smaller than min
	// I swap my content with parent and go to parent
	while (v != 1 && a[v/2]<a[v]) {
		swap(a[v/2],a[v]);
		v = v / 2;
	}
}

void push(int x) {
	n++;
	a[n] = x;
	heapify_up(n);
}

int top() {
	if (n == 0) {
		cout << "[Error] Heap is empty\n";
		exit(0);
	}
	return a[1];
}

void print(int v = 1, int tab = 0) {
	if (v == 1)
		cout << "-----\n";

	if (v > n)
		return;
	
	print(2 * v + 1, tab + 1);

	for (int i = 0; i < tab; i++) cout << "| ";
	cout << a[v] << "\n";
	
	print(2 * v, tab + 1);
}

void heapify_down(int v) {
	// find max index 
	// among {a[v], a[2v], a[2v+1]}
	int p = v;
	int l = 2*v;
	int r = 2*v+1;
	/*
		try print()
		to see step by step
	*/
	if (l <= n && a[l] > a[p]) p = l;
	if (r <= n && a[r] > a[p]) p = r;
	if (p == v)
		return;
	// << p != v => p == l or r
	swap(a[p], a[v]);
	heapify_down(p);
}

void pop() {
	swap(a[1], a[n]);
	n--;
	heapify_down(1);
}

void build() { // works in O(n), not O(nlogn)
	for (int i = n/2; i >= 1; i--) { // O(n)
		heapify_down(i); // O(log(n))
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		/*
		cin >> x;
		push(x);
			it is O(nlog(n))
		*/
	}

	build();

	push(1); print();
	push(3); print();
	push(5); print();
	push(2); print();
	push(9); print();
	push(1); print();
	cout << "~~~~~~~~\n";
	pop(); print();


	return 0;
}