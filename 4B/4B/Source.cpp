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
  int n;
  char ch;
  std::map<std::string, int> num;

  //fin >> n;
  while (!fin.eof())
  {
    
    fin >> s;
    if (s == "    ") continue;
    if (num.find(s) == num.end())
      num.insert(std::pair<std::string, int>(s, 0));
    fout << num[s] << ' ';
    //std::cout << s << std::endl;
    num[s]++;
    s = "    ";
  }
}