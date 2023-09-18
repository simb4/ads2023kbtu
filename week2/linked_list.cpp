#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <queue>

using namespace std;


struct node {
  int data;
  node* nxt;

  node() {
    this->data = 0;
    this->nxt = NULL;
  }
  node(int data) {
    this->data = data;
    this->nxt = NULL;
  }
  node(int data, node* nxt) {
    this->data = data;
    this->nxt = nxt;
  }

  void push_back(int x) {
    if (nxt == NULL) {
      nxt = new node(x);
    } else {
      nxt->push_back(x);
    }
  }

  void print() {
    cout << "[" << data << "]";
    if (nxt != NULL) {
      cout << "->";
      nxt->print();
    }
  }
};

struct linked_list {
  node* head = NULL; // front, the beginning

  bool is_empty() {
    return head == NULL;
  }

  void push_back(int x) {
    /*
      O(n) time, where n is num of elements in a list
    */
    if (is_empty())
      head = new node(x);
    else 
      head->push_back(x);
  }

  void push_front(int x) {
    if (is_empty())
      head = new node(x);
    else {
      node *v = new node(x, head);
      // we have a new begining
      head = v;
    }

  }

  void pop_back() {
    if (is_empty()) {
      cerr << "LinkedList ERROR: list is empty\n";
      exit(0);
    }

    if (head->nxt == NULL) {
      delete head;
      head = NULL;
      return;
    }
    
    node *cur = head;
    while (cur->nxt->nxt != NULL) {
      cur = cur->nxt;
    }
    node *to_delete = cur->nxt; // keep track of pointer to free
    cur->nxt = NULL; // declare new tail
    delete to_delete; // free memory
  }

  void pop_front() {
    if (is_empty()) {
      cerr << "LinkedList ERROR: list is empty\n";
      exit(0);
    }
    node *new_head = head->nxt;
    delete head;
    head = new_head;
  }

  void print() {
    if (head == NULL)
      cout << "[]";
    else {
      head->print();
    }
    cout << "\n";

  }
};

int main () {
  int tests;
  cin >> tests;

  linked_list L;

  for (int i = 0; i < tests; i++) {
    
    string s;
    cin >> s;

    int x;
    if (s == "push_back") {
      cin >> x;
      L.push_back(x);
      cout << "OK\n";
    }
    if (s == "push_front") {
      cin >> x;
      L.push_front(x);
      cout << "OK\n";
    }
    if (s == "pop_front") {
      L.pop_front();
      cout << "OK\n"; 
    }
    if (s == "pop_back") {
      L.pop_back();
      cout << "OK\n"; 
    }
    L.print();
  }



  return 0;
}






