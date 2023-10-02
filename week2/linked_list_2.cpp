#include <iostream>

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
    if (this->nxt == NULL) { // I am tail
      node *new_node = new node(x);
      this->nxt = new_node;
    } else { // I am not tail
      this->nxt->push_back(x);
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
// LEETCODE.COM

struct linked_list {
  // front, the beginning
  node* head = NULL; 

  // we can store
  node *tail = NULL;
  // but we won't for educational reasons

  bool is_empty() {
    return head == NULL;
  }

  void push_back(int x) {
    if (head == NULL)
      head = new node(x);
    else {
      head->push_back(x);
    }
  }

  void push_front(int x) {
    node* new_head = new node(x, head);
    head = new_head;
  }

  void pop_back() {
    if (head == NULL) {
      cout << "[LinkedListError] List is empty\n";
      exit(0);
    }
    if (head->nxt == NULL) {
      delete head;
      head = NULL;
    }

    node *cur = head;
    while (cur->nxt->nxt != NULL) {
      // make a step forward
      cur = cur->nxt;
    }

    // cur == pretail
    node *old_tail = cur->nxt;
    delete old_tail;
    // cur is a new tail
    cur->nxt = NULL; 
  }

  void pop_front() {
    if (head == NULL) {
      cout << "[LinkedListError] List is empty\n";
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






