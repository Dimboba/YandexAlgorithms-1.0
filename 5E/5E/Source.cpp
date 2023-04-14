#include<string>
#include<iostream>
//#include<vector>
//#include<cmath>
#include<fstream>
#include<map>


int main()
{

  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);

  int n, k, nw, sum = 0, j = 1, left, right, ans=1000000;
  fin >> n >> k;
  int* trees = new int[n + 1];
  std::map<int, int> colours;

  for (int i = 1; i < n + 1; i++)
  {
    fin >> nw;
    trees[i] = nw;
    if (colours.find(nw) == colours.end())
      colours.insert(std::pair<int, int>(nw, 0));
  }
  for (int i = 1; i <= n; i++)
  {
    while ((sum < k) && j <= n)
    {
      if (colours[trees[j]] == 0)
        sum++;
      colours[trees[j]]++;
      //std::cout << i << ' ' << j << ' ' << sum << std::endl;
      j++;
      }
    //std::cout << i << ' ' << j << ' ' << sum << std::endl;
    if (sum == k && ans > (j - i))
    {
      ans = j - i;
      left = i;
      right = j - 1;
      //fout << i << ' ' << j - 1 << '\n';
    }
    colours[trees[i]]--;
    //std::cout << colours[trees[i]]<<' ';
    if (colours[trees[i]] == 0)
    {
      sum--;
      //std::cout << i << ' ' << j << ' ' << sum << std::endl;
    }
  }
  fout << left << ' ' << right;
}

