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

  int n, k, j = 0, last;
  long long ans = 0;
  fin >> n >> k;
  int* cards = new int[n];

  for (int i = 0; i < n; i++)
  {
    fin >> cards[i];
  }
  for (int i = 0; i < n; i++)
  {
    while (cards[i] * k >= cards[j] && j < n)
    {
      if(j - i > 1)
        ans += (j - i - 1);
      j++;
      std::cout << j << ' ' << i << std::endl;
    }
  }
  fout << ans;
}

