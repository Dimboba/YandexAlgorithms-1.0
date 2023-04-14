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
  
  int n, k, length = 0, start, j = 1;
  char over = ' ';
  fin >> n >> k;
  char* str = new char[n+1];
  std::map<char, int> number;
  for (char i = 'a'; i <= 'z'; i++)
  {
    number.insert(std::pair<char, int>(i, 0));
  }
  for (int i = 1; i <= n; i++)
  {
    fin >> str[i];
  }
  for (int i = 1; i <= n; i++)
  {
    while (over == ' ' && j <= n)
    {
      number[str[j]]++;
      if (number[str[j]] > k)
        over = str[j];
      else if (j - i + 1 > length)
      {
        length = j - i + 1;
        start = i;
      }

        //std::cout << i << ' ' << j << '!' << over << std::endl;
      //std::cout << str[j] << number[str[j]] << '-' << over << ' ';
      j++;
    }
    //std::cout << i << ' ' << j - 1 << '!' << over << '!' << std::endl;
    number[str[i]]--;
    if (number[str[i]] == k && str[i] == over)
      over = ' ';
  }

  fout << length << ' ' << start;
}

