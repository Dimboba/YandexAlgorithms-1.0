#pragma once
#include<iostream>
template <typename Type> class BinaryTree
{
private:
  std::pair<int, int>* sons;
  int* parent;
  int* height;
  int maxElements, firstFree;
  int rootIndex = 0;
  Type* memory;
public:

  BinaryTree(int maxElements1):maxElements(maxElements1)
  {
    firstFree = 0;
    height = new int[maxElements];
    parent = new int[maxElements];
    memory = new Type[maxElements];
    sons = new std::pair<int, int>[maxElements];
    for (int i = 0; i < maxElements; i++)
    {
      sons[i].first = i+1;
      sons[i].second = -1;
      height[i] = -1;
    }
  }

  BinaryTree()
  {
    BinaryTree(100);
  }

  //~BinaryTree();
  int find(Type val, int index = -1)
  {
    if (index == -1) index = rootIndex;
    if (val == memory[index])
      return index;
    else if (val < memory[index])
    {
      if (sons[index].first == -1)
        return -1;
      else
        return find(val, sons[index].first);
    }
    else if (val > memory[index])
    {
      if (sons[index].second == -1)
        return -1;
      else
        return find(val, sons[index].second);
    }
  }

  void createnewnode(Type val, int parHeight = 0, int parent1 = -1)
  {
    int i = firstFree;
    firstFree = sons[i].first;
    height[i] = parHeight + 1;
    memory[i] = val;
    parent[i] = parent1;
    sons[i].first = -1;
    sons[i].second = -1;
  }

  void add(Type val, int index = -1)
  {
    if (index == -1) index = rootIndex;
    if (memory[index] == val)
    {
      std::cout << "Element is already exists";
    }
    else if (val < memory[index])
    {
      if (sons[index].first == -1)
      {
        sons[index].first = firstFree;
        createnewnode(val, height[index], index);
      }
      else
        add(val, sons[index].first);
    }
    else if (val > memory[index])
    {
      if (sons[index].second == -1)
      {
        sons[index].second = firstFree;
        createnewnode(val, height[index], index);
      }
      else
        add(val, sons[index].second);
    }
  }

  int findlowest(int index)
  {
    if (sons[index].first == -1)
      return index;
    else
      return findlowest(sons[index].first);
  }

  void del(Type val)
  {
    int index = find(val);
    int par = parent[index];
    if (sons[index].first == -1 && sons[index].second == -1)
    {
      if (val < memory[par])
        sons[par].first = -1;
      else if (val > memory[par])
        sons[par].second = -1;
      sons[index].first = firstFree;
      firstFree = index;
      height[index] = -1;
    }
    else if (sons[index].first == -1 || sons[index].second == -1)
    {
      int next;
      if (sons[index].first == -1) next = sons[index].second;
      else if(sons[index].second == -1) next = sons[index].first;
      if (val < memory[par])
        sons[par].first = next;
      else if (val > memory[par])
        sons[par].second = next;
      height[next]--;
      height[index] = -1;
      if (index == rootIndex)
        rootIndex = next;
    }
    else if (sons[index].first != -1 && sons[index].second != -1)
    {
      int next;
      next = findlowest(sons[index].second);
      del(memory[next]);
      memory[index] = memory[next];
      height[index] = height[next];
      height[next] = -1;
    }
  }
  int maxHeight()
  {
    int mx = 0;
    for (int i = 0; i < maxElements; i++)
      if (height[i] > mx) mx = height[i];
    return mx;
  }
  int aboba(int bruh)
  {
    int a = 1;
    std::cout << memory[bruh] + a;
  }
};


