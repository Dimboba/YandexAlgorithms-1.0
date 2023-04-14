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

  int n, m, j = 0, x, a, b;
  long long ans = 0;
  fin >> n;
  int* y = new int[n + 1];
  int* prefix_y = new int[n + 2];
  int* postfix_y = new int[n + 2];
  prefix_y[1] = 0;
  postfix_y[n] = 0;
  for (int i = 1; i <= n; i++)
  {
    fin >> x >> y[i];
  }
  for (int i = 2; i <= n; i++)
  {
    if (y[i] > y[i - 1])
      prefix_y[i] = prefix_y[i - 1] + (y[i] - y[i - 1]);
    else
      prefix_y[i] = prefix_y[i - 1];
    //fout << prefix_y[i]<<' ';
  }
  //fout << '\n';
  for (int i = n - 1; i >= 1; i--)
  {
    if (y[i] > y[i + 1])
      postfix_y[i] = postfix_y[i + 1] + (y[i] - y[i + 1]);
    else
      postfix_y[i] = postfix_y[i + 1];
    //fout << postfix_y[i]<<' ';
  }
  //fout << '\n';
  fin >> m;
  for (int i = 0; i < m; i++)
  {
    fin >> a >> b;
    if (a == b)
      fout << 0 << '\n';
    else if (a > b)
      fout << postfix_y[b] - postfix_y[a] << '\n';
    else
      fout << prefix_y[b] - prefix_y[a] << '\n';
  }
}

