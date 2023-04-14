
#include<string>
#include<iostream>
#include<map>
#include<fstream>
//#include<iterator>


int main()
{
  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);

  std::string s = "    ";
  int n, k, nw;
  char ch;
  std::map<int, int> num;
  fin >> n;
  for (int i = 1; i <= n; i++)
  {
    fin >> nw;
    num.insert(std::pair<int, int>(i, nw));
  }
  fin >> k;
  for (int i = 0; i < k; i++)
  {
    fin >> nw;
    num[nw]--;
  }
  for (int i = 1; i <= n; i++)
  {
    //std::cout << num[i]<<' ';
    if (num[i] < 0)
      fout << "YES" << '\n';
    else
      fout << "NO" << '\n';
  }
}