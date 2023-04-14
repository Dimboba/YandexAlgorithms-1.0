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

  int n, m, nw, delta = 1000000000, ans_n, ans_m, j = 0;
  //std::vector<long long> mass_n, mass_m, prefix_n, prefix_m;
  fin >> n;
  int* mass_n = new int[n];
  for (int i = 0; i < n; i++)
  {
    fin >> mass_n[i];
    //std::cout << mass_n[i];
  }
  fin >> m;
  int* mass_m = new int[m];
  for (int i = 0; i < m; i++)
  {
    fin >> mass_m[i];
    //std::cout << mass_m[i];
  }
  for (int i = 0; i < n; i++)
  {
    while (mass_n[i] >= mass_m[j] && j < m)
    {
      if (delta > (mass_n[i] - mass_m[j]))
      {
        delta = (mass_n[i] - mass_m[j]);
        ans_n = mass_n[i];
        ans_m = mass_m[j];
        //std::cout << i << ' ' << j << ' ' << delta;
        
      }
      j++;
    }
  }
  j = 0;
  for (int i = 0; i < m; i++)
  {
    while (mass_m[i] >= mass_n[j] && j < n)
    {
      if (delta > (mass_m[i] - mass_n[j]))
      {
        delta = (mass_m[i] - mass_n[j]);
        ans_n = mass_n[j];
        ans_m = mass_m[i];
        //std::cout << i << ' ' << j << ' ' << delta;

      }
      j++;
    }
  }
  fout << ans_n << ' ' << ans_m;
}

