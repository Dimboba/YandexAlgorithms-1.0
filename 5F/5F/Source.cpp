#include<string>
#include<iostream>
//#include<vector>
//#include<cmath>
#include<fstream>
//#include<map>


int main()
{

  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);

  int n, m, nw, b, c, cond[1001], num[1001];
  long long ans = 0;
  fin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++)
  {
    fin >> a[i];
  }
  fin >> m;
  for (int i = 0; i < 1001; i++)
  {
    cond[i] = 9999;
    num[i] = 0;
  }
  for (int i = 0; i < m; i++)
  {
    fin >> b >> c;
    for (int j = b; j >= 0; j--)
    {
      if (cond[j] > c)
        cond[j] = c;
    }
  }
  for (int i = 0; i < n; i++)
  {
    ans += cond[a[i]];
    //std::cout << a[i] << ' ' << cond[a[i]] << std::endl;
  }
  fout << ans;
}

