#pragma once
#include<iostream>
#include<list>
#include<string>
#include<fstream>
#include<map>
template <typename Type> class Tree
{
public:
  int* desc; // число потомков
  std::list<int>* sons;
  int* parent;
  int* height;
  int maxElements, firstFree;
  //int rootIndex;
  int* next; // если next[i] == -1 то данный i уже заполнен
  Type* memory;
public:
  Tree(int maxElements1) : maxElements(maxElements1)
  {
    firstFree = 0;
    height = new int[maxElements];
    parent = new int[maxElements];
    memory = new Type[maxElements];
    sons = new std::list<int>[maxElements];
    next = new int[maxElements];
    desc = new int[maxElements];
    for (int i = 0; i < maxElements; i++)
    {
      next[i] = i + 1;
      height[i] = -1;
      parent[i] = -1;
      desc[i] = -1;
    }
  }
   
  Tree() { Tree(100); }

  int find(Type val)
  {
    for (int i = 0; i < maxElements; i++)
      if (memory[i] == val) return i;
    return -1;
  }

  void createnewnode(Type val)
  {
    int index = firstFree;
    memory[index] = val;
    firstFree = next[index];
    next[index] = -1;
  }

  void connecttofather(int index, int parIndex)
  {
    parent[index] = parIndex;
    sons[parIndex].push_back(index);
  }

  void add(Type val, Type par)
  {
    int index = find(val);
    if (index == -1)
    {
      int parIndex = find(par);
      if (parIndex == -1)
      {
        parIndex = firstFree;
        createnewnode(par);
      }
      index = firstFree;
      createnewnode(val);
      connecttofather(index, parIndex);
    }
    else 
    {
      int parIndex = find(par);
      if (parIndex == -1)
      {
        parIndex = firstFree;
        createnewnode(par);
      }
      connecttofather(index, parIndex);
    }
  }
  
  int findRoot()
  {
    for (int i = 0; i < maxElements; i++)
    {
      if (next[i] == -1 && parent[i] == -1)
        return i;
    }
    return -1;
  }

  void calc(int rootIndex, int parHeight = 0)
  {
    std::list<int>::iterator it;
    height[rootIndex] = parHeight;
    desc[rootIndex] = sons[rootIndex].size();
    for (it = sons[rootIndex].begin(); it != sons[rootIndex].end(); it++)
    {
      calc(*it, parHeight+1);
      desc[rootIndex] += desc[*it];
    }
  }
};

int main()
{
  std::ifstream fin("input.txt", std::ios::in);
  std::map<std::string, int> descs;
  int n;
  fin >> n;
  Tree<std::string> fam(n);
  std::string son, par;
  for (int i = 0; i < n - 1; i++)
  {
    fin >> son >> par;
   // descs.insert(std::pair<std::string, int>(son, 0));
   // descs.insert(std::pair<std::string, int>(par, 0));
    fam.add(son, par);
  }
  std::map<std::string, int>::iterator it;
  std::list<int>::iterator it1;
  fam.calc(fam.findRoot());
  for (int i = 0; i < n; i++)
  {
    //descs[fam.memory[i]] = fam.desc[i]; // для первой
    descs[fam.memory[i]] = fam.height[i]; // для второй
  }
  for (it = descs.begin(); it != descs.end(); it++)
  {
    std::cout << it->first << ' ' << it->second<< std::endl;
  }
  //fam.sons[fam.find("Paul_I")].pop_back();
 // std::cout << fam.memory[fam.sons[fam.find("Paul_I")].back()];
  //std::cout << fam.memory[fam.findRoot()];
}
