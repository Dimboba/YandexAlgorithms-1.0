#include<string>
#include<iostream>
//#include<vector>
#include<cmath>
#include<fstream>
//#include<map>

struct params { long long w, h, ans; };

long long mymax(long long a, long long b)
{
  if (a > b) return a;
  return b;
}
bool check(long long m, params par)
{
  std::cout << (m / par.w) * (m / par.h) << std::endl;
  if ((m / par.w) * (m / par.h) >= par.ans) return true;
  return false;
}

long long lbinsearch(long long l, long long r, params par)
{
  while (l < r)
  {
    std::cout << l << ' ' << r <<std::endl;
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

  long long n, k, mx;
  params a;
  fin >> a.h >> a.w >> a.ans;
  mx = mymax(a.w, a.h) * a.ans;
  long long square = sqrt(mx) * sqrt(mx) + 100;
  //fout << square << std::endl;
  fout << lbinsearch(0, square, a);

}

