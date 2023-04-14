//#include<string>
#include<iostream>
#include<set>
#include<fstream>
#include<iterator>


std::set<std::string> find_union(std::set<std::string>* a, std::set<std::string>* b)
{
  std::set<std::string> shared;
  std::set<std::string>::iterator it = a->begin();
  for (it = a->begin(); it != a->end(); it++)
  {
    if (b->find(*it) != b->end())
    {
      shared.insert(*it);
    }
  }
  return shared;
}

std::set<std::string> only_there(std::set<std::string>* main, std::set<std::string>* second)
{
  std::set<std::string> unique, shared;
  std::set<std::string>::iterator it;
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

  std::string s;
  int n, m, fst;
  std::set<std::string> nw, shared, full;
  std::set<std::string>::iterator it;

  fin >> n;
  for (int i = 0; i < n; i++)
  {
    fin >> m;
    for (int j = 0; j < m; j++)
    {
      fin >> s;
      nw.insert(s);
      full.insert(s);
    }
    if (i == 0) { shared = nw; }
    else { shared = find_union(&nw, &shared); }
    nw.clear();
  }
  fout << shared.size() << '\n';
  for (it = shared.begin(); it != shared.end(); it++)
  {
    fout << *it << '\n';
  }
  fout << full.size() << '\n';
  for (it = full.begin(); it != full.end(); it++)
  {
    fout << *it << '\n';
  }

}