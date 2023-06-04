// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>

struct Node {
  std::string first_word;
  int count;
  Node* left;
  Node* right;
  explicit Node(const std::string& word) : first_word(word), count(1), left(nullptr), right(nullptr) {}
};
template<typename T>
class BST {
 private:
  Node * root;
  Node* addNode(Node* root, const std::string& word) {
    if (root == nullptr) 
    {
      return new Node(word);
    }
    if (word < root->word) {
      root->left = addNode(root->left, word);
    } else if (word > root->word) {
      root->right = addNode(root->right, word);
    } else {
      root->count++;
    }
    return root;
  }
  Node* searchNode(Node* root, const std::string& word) {
    if (root == nullptr || root->word == word) {
      return root;
    }
    if (word < root->word) {
      return searchNode(root->left, word);
    } else {
      return searchNode(root->right, word);
    }
  }
  int get_depth(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    int left_depth = get_depth(root->left);
    int right_depth = get_depth(root->right);
    return std::max(left_depth, right_depth) + 1;
  }

 public:
  BST() : root(nullptr) {}
  void addElem(const std::string& word) {
    root = addNode(root, word);
  }
  int depth() {
    return get_depth(root) - 1;
  }
  int search(const std::string& word) {
    Node* node = searchNode(root, word);
    return (node != nullptr) ? node->count : 0;
  }
};
#endif  // INCLUDE_BST_H_
