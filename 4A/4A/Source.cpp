#include<string>
#include<iostream>
#include<map>
#include<fstream>
//#include<iterator>


int main()
{
  std::ifstream fin("input.txt");
  std::ofstream fout("output.txt");

  std::string s1, s2;
  int n;
  char ch;
  std::map<std::string, std::string> syn;

  fin >> n;
  for (int i = 0; i < n; i++)
  {
    //std::getline(fin, s1, ' ');
    //std::getline(fin, s2);
    
    fin >> s1 >> s2;
    syn[s1] = s2;
    syn[s2] = s1;
    //fout << s1 << ' ' << s2 << '\n';
  }
  fin >> s1;
  fout << syn[s1];
}