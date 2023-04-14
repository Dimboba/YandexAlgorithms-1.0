#include<string>
#include<iostream>
//#include<vector>
#include<cmath>
#include<fstream>
//#include<map>

struct params { long long n, m, t; };

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
  long long flower = (par.m - 2 * m) * (par.n - 2 * m);
  if (par.m * par.n - flower <= par.t) return true;
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
  fin >> a.n >> a.m >> a.t;
  fout << rbinsearch(0, mymin(a.n, a.m) / 2, a);
}

