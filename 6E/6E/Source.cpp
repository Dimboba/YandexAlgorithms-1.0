#include<string>
#include<iostream>
//#include<vector>
#include<cmath>
#include<fstream>
//#include<map>

struct params { long long mark2, mark3, mark4; };

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
  long long num = (m + par.mark2 + par.mark3 + par.mark4);
  long long sum = (m * 5 + par.mark2 * 2 + par.mark3 * 3 + par.mark4 * 4);
  if (2 * sum >= 7 * num) return true; // домножил неравенство с обеих стороон на 2, чтобы уйти от дробей
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

int main()
{

  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);
  params a;
  fin >> a.mark2 >> a.mark3 >> a.mark4;
  fout << lbinsearch(0, (a.mark2 + a.mark3 + a.mark4), a);
}

