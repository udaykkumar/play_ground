#include <iostream>

struct node {
  int value_;
  struct node *left, *right;

  node(int v) : value_(v) {}
};

void inorder(struct node *root) {
  if (root) {
    std::cout << root->value_ << " ";
    inorder(root->left);
    inorder(root->right);
  }
}

struct node *bst(int arr[], int lo, int hi) {
  if (lo > hi) return nullptr;

  int mid = (lo + hi) >> 1;
  struct node *n = new node(arr[mid]);
  if (not n) return nullptr;

  n->left = bst(arr, lo, mid - 1);
  n->right = bst(arr, mid + 1, hi);

  return n;
}

int main(int argc, char const *argv[]) {
  int size = 1000;
  int arr[size];
  for (int i = 0; i < size; ++i) {
    arr[i] = i;
  }
  struct node *r = bst(arr, 0, size - 1);
  inorder(r);
  return 0;
}