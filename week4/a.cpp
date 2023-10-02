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

const int N = (int)1e5;

struct node {
    int key;
    node *l = NULL; // left son
    node *r = NULL; // right son 
    node() {}
    node(int key) {
        this->key = key;
    }
};

node *root;

node* insert(node *v, int key) {
    if (v == NULL) {
        v = new node(key);
        return v;
    }
    if (key <= v->key)
        v->l = insert(v->l, key);
    else
        v->r = insert(v->r, key);
    return v;
}

node* find(node *v, int key) {
    if (v == NULL)
        return NULL;
    if (v->key == key)
        return v;
    if (key <= v->key)
        return find(v->l, key);
    return find(v->r, key);
}

void del_node_with_no_left_child(node *v, node *par, bool is_left) {
    if (is_left) {
        par->l = v->r;
    } else {
        par->r = v->r;
    }
    delete v;
}

bool del(node* root, int key) {
    if (root == NULL)
        return false;

    // find vertex v with key
    // and also its parent and which child (left or right)
    node *par = NULL;
    node *v = root;
    bool is_left = false;
    while (v->key != key) {
        if (key < v->key) {
            par = v;
            v = v->l;
            is_left = true;
        }
        else {
            par = v;
            v = v->r;
            is_left = false;
        }
        if (v == NULL)
            return false;
    }

    // v is a leaf
    if (v->l == NULL && v->r == NULL) {
        if (is_left)
            par->l = NULL;
        else
            par->r = NULL;

        delete v;
        return true;
    }

    // v has no left child
    if (v->l == NULL) {
        del_node_with_no_left_child(v, par, is_left);
        return true;
    }

    // v has two children
    int newKey;
    if (v->r->l == NULL) {
         newKey = v->r;
        del_node_with_no_left_child(v->r, v, false);
    } else {
        node *lpar = v;
        node *leftmost = v->r;
        while (leftmost->l != NULL) {
            lpar = leftmost;
            leftmost = leftmost->l;
        }
        newKey = leftmost->key;
        del_node_with_no_left_child(leftmost, lpar, true);
    }

    v->key = newKey;
}

void print(node* v, int tab = 0) {
    for (int i = 0; i < tab; i++)
        cout << "  ";
    if (v == NULL)
        cout << "NULL\n"; 
    else {
        cout << v->key << "\n";
        print(v->l, tab+1);
        print(v->r, tab+1);
    }
}

int main () {
    
    root = insert(root, 25);
    insert(root, 15);
    insert(root, 10);
    insert(root, 4);
    insert(root, 12);
    insert(root, 22);
    insert(root, 18);
    insert(root, 24);

    insert(root, 50);
    insert(root, 35);
    insert(root, 44);

    insert(root, 70);
    insert(root, 66);

    

    insert(root, 23);

    print(root);

    return 0;
}






