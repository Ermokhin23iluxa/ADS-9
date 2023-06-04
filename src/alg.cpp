// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> tree;
  std::ifstream file(filename);
  std::string first_line;
  std::string text;
  std::string addSymb;
  while (std::getline(file, first_line)) {
    text = text + first_line + " ";
  }
  for (auto a : text) {
    if (isalpha(a)) {
      a = tolower(a);
      addSymb += a;
    }
    else {
      tree.addElem(addSymb);
      addSymb = "";
    }
  }
  file.close();
  return tree;
}
