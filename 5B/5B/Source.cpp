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

  int n, k, nw, j = 1;
  long long ans = 0;
  fin >> n >> k;
  long long* prefix = new long long[n+1];
  prefix[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    fin >> nw;
    prefix[i] = prefix[i - 1] + nw;
    //std::cout << prefix[i] << ' ';
  }
  //std::cout << std::endl;
  for (int i = 0; i <= n; i++)
  {
    while ((prefix[j] - prefix[i]) <= k && j <= n)
    {
      if (prefix[j] - prefix[i] == k)
      {
        ans++;
        //std::cout << i << ' ' << j << std::endl;
      }
      j++;
    }
  }
  fout << ans;
}

