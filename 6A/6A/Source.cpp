#include<string>
#include<iostream>
//#include<vector>
//#include<cmath>
#include<fstream>
//#include<map>

struct params { int* mass; int ans; };

bool check(int m, params par)
{
 // std::cout << ' ' << par.mass[m] << ' ' << par.ans << std::endl;
  if (par.mass[m] >= par.ans) return true;
  else return false;
}

int lbinsearch(int l, int r, params par)
{
  while (l < r)
  {
    //std::cout << l << ' ' << r;
    int m = (l + r) / 2;
    if (check(m, par))
      r = m;
    else
      l = m + 1;
  }
  return l;
}

int main()
{

  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);
  
  int n, k;
  params a;
  fin >> n >> k;
  a.mass = new int[n];
  for (int i = 0; i < n; i++)
  {
    fin >> a.mass[i];
  }
  for (int i = 0; i < k; i++)
  {
    fin >> a.ans;
    if (a.mass[lbinsearch(0, n, a)] == a.ans)
      fout << "YES";
    else
      fout << "NO";
    fout << '\n';
  }
  
}

