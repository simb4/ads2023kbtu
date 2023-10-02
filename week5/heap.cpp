#include <iostream>

using namespace std;

const int N = (int)1e5 + 5;

int n; // size
int a[N]; // storage


void heapify_up(int v) {
	while (v != 1 && a[v/2] < a[v]) {
		swap(a[v/2], a[v]);
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
	// find max among v, 2v, 2v+1
	int p = v;
	int l = 2*v;
	int r = 2*v+1;
	if (l <= n && a[l] > a[p]) p = l;
	if (r <= n && a[r] > a[p]) p = r;
	if (p == v) // if v is greater than l&r
		return;
	// p = l or r (left or right son)
	swap(a[p], a[v]);
	heapify_down(p);
}

void pop() {
	swap(a[1],a[n]);
	n--;
	heapify_down(1);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	push(1); print();
	push(3); print();
	push(5); print();
	push(2); print();
	push(9); print();
	push(1); print();
	
	pop(); print();


	return 0;
}