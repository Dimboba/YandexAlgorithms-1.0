#include<string>
#include<iostream>
//#include<vector>
#include<cmath>
#include<fstream>
//#include<map>

struct params { long long* height; long long n, r, c; };

int compare(const void* a, const void* b)
{
  return (*(int*)a - *(int*)b);
}

void bubblesort(long long* mass, long long size)
{
  for (long long i = 0; i < size; i++)
  {
    for (long long j = 0; j < size - i - 1; j++)
    {
      if (mass[j] > mass[j + 1])
      {
        long long temp = mass[j];
        mass[j] = mass[j + 1];
        mass[j + 1] = temp;
      }
    }
  }
}

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
  //std::cout << m << std::endl;
  long long sum = 0;
  for (long long i = 0; i + par.c - 1 < par.n; i++)
  {
    if (par.height[i + par.c - 1] - par.height[i] <= m)
    {
      //for (int j = i; j < i + par.c; j++) std::cout << j << ':' << par.height[j] << ' ';
      //std::cout << std::endl;
      sum += 1;
      i = i + par.c - 1;
    }
  }
  //std::cout << std::endl;
  if (sum >= par.r) return true;
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
  long long mx = 0, mn = 1000000000;
  fin >> a.n >> a.r >> a.c;
  if (a.c == 1)
  {
    fout << 0;
    return 0;
  }
  a.height = new long long[a.n];
  //long long* mass = new long long[a.n];
  for (int i = 0; i < a.n; i++)
  {
    fin >> a.height[i];
    if (mx < a.height[i]) mx = a.height[i];
    if (mn > a.height[i]) mn = a.height[i];
  }
  qsort(a.height, a.n, sizeof(long long), compare);
  //bubblesort(a.height, a.n);
  fout << lbinsearch(0, mx - mn, a);
}

