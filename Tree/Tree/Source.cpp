#include"BinaryTree.h"
//#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
//#include<set>

int main()
{
  std::ifstream fin("input.txt", std::ios::in);
  std::vector<int> vec;
  
  BinaryTree<int> aboba(50);
  aboba.createnewnode(3);
  aboba.add(4);
  aboba.add(0);
  aboba.add(1);
  aboba.add(-1);
  std::cout << aboba.find(0) << std::endl;
  std::cout << aboba.maxHeight();
  
}

