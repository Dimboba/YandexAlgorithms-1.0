#include<string>
#include<iostream>
//#include<vector>
#include<cmath>
#include<fstream>
//#include<map>

struct params { long long n, k; long long* l; };

long long mymax(long long a, long long b)
{
  if (a > b) return a;
  return b;
}

long long mymin(long long a, long long b)
{
  if (a < b) return a;
  return b;
}

bool check(long long m, params par)
{
  int sum = 0;
  for (int i = 0; i < par.n; i++)
  {
    sum += par.l[i] / m;
  }
  if (sum >= par.k) return true;
  return false;
}

long long lbinsearch(long long l, long long r, params par)
{
  while (l < r)
  {
    //std::cout << l << ' ' << r << std::endl;
    long long m = (l + r) / 2;
    if (check(m, par))
      r = m;
    else
      l = m + 1;
  }
  return l;
}

long long rbinsearch(long long l, long long r, params par)
{
  long long m = (l + r + 1) / 2;
  while (l < r)
  {
    //std::cout << l << ' ' << r << std::endl;
    long long m = (l + r + 1) / 2;
    if (check(m, par))
      l = m;
    else
      r = m - 1;
  }
  return l;
}

int main()
{

  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);
  params a;
  int mx = 0;
  fin >> a.n >> a.k;
  a.l = new long long[a.n];
  for (int i = 0; i < a.n; i++)
  {
    fin >> a.l[i];
    if (a.l[i] > mx)
      mx = a.l[i];
  }
  fout << rbinsearch(0, mx, a);
}

