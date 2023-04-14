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
  
  int n, r, j = 0;
  long long ans = 0;
  fin >> n >> r;
  int* d = new int[n];
  for (int i = 0; i < n; i++)
  {
    fin >> d[i];
  }
  for (int i = 0; i < n; i++)
  {
    while ((d[j] - d[i]) <= r && j < n)
    {
      //std::cout << d[j] << ' ' << d[i] << std::endl;
      //ans++;
      j++;
    }
    //fout << d[j] << ' ' << d[i] << std::endl;
    ans += (n - j);
  }
  fout << ans;
}

