#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode {
  int data;
  struct BstNode *left;
  struct BstNode *right;
} node;

node *get_node(int data);
node *insert(node *root, int data);
int in_tree(node *root, int data);
int get_min(node *root);
int get_max(node *root);
void print_tree(node *root);

int main() {
  node *root = NULL;
  root = insert(root, 10);
  root = insert(root, 11);
  root = insert(root, 12);
  root = insert(root, 13);
  root = insert(root, 14);
  root = insert(root, 140);
  root = insert(root, 15);
  root = insert(root, 16);
  root = insert(root, 1);
  print_tree(root);
  if (in_tree(root, 13))
    printf("node is in tree\n");

  printf("min is : %d\n", get_min(root));
  printf("max is : %d\n", get_max(root));
}

node *get_node(int data) {
  node *bst_node = malloc(sizeof(node));
  bst_node->data = data;
  bst_node->left = bst_node->right = NULL;
  return bst_node;
}

node *insert(node *root, int data) {
  if (root == NULL) {
    root = get_node(data);
  } else if (data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

int in_tree(node *root, int data) {
  if (root == NULL)
    return 0;
  else if (data == root->data)
    return 1;
  else if (data <= root->data)
    return in_tree(root->left, data);
  else
    return in_tree(root->right, data);
}

int get_min(node *root) {
  if (root == NULL) {
    printf("the tree is empty");
    exit(EXIT_FAILURE);
  }
  if (root->left == NULL)
    return root->data;
  else
    return get_min(root->left);
}

int get_max(node *root) {
  if (root == NULL) {
    printf("the tree is empty");
    exit(EXIT_FAILURE);
  }

  if (root->right == NULL)
    return root->data;
  else
    return get_max(root->right);
}

void print_tree(node *root) {
  if (root == NULL)
    return;
  print_tree(root->left);
  printf("%d\n", root->data);
  print_tree(root->right);
}
