//#include<string>
//#include<iostream>
#include<set>
#include<fstream>
#include<iterator>


std::set<int> find_union(std::set<int>* a, std::set<int>* b)
{
  std::set<int> shared;
  std::set<int>::iterator it = a->begin();
  for (it = a->begin(); it != a->end(); it++)
  {
    if (b->find(*it) != b->end())
    {
      shared.insert(*it);
    }
  }
  return shared;
}

std::set<int> only_there(std::set<int>* main, std::set<int>* second)
{
  std::set<int> unique, shared;
  std::set<int>::iterator it;
  shared = find_union(main, second);
  for (it = main->begin(); it != main->end(); it++)
  {
    if (shared.find(*it) == shared.end())
    {
      unique.insert(*it);
    }
  }
  return unique;
}

int main()
{
  std::ifstream fin("input.txt");
  std::ofstream fout("output.txt");

  int n, m, just;
  std::set<int> a, b, shared, only_a, only_b;
  std::set<int>::iterator it;

  fin >> n >> m;
  for (int i = 0; i < n; i++) { fin >> just; a.insert(just); }
  for (int i = 0; i < m; i++) { fin >> just; b.insert(just); }
  
  shared = find_union(&a, &b);
  only_a = only_there(&a, &b);
  only_b = only_there(&b, &a);

  fout << shared.size()<<'\n';
  for (it = shared.begin(); it != shared.end(); it++)
    fout << *it<< ' ';
  fout << '\n' << only_a.size() << '\n';
  for (it = only_a.begin(); it != only_a.end(); it++)
    fout << *it << ' ';
  fout << '\n' << only_b.size() << '\n';
  for (it = only_b.begin(); it != only_b.end(); it++)
    fout << *it << ' ';
}