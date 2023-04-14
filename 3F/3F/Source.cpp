#include<string>
//#include<iostream>
#include<set>
#include<fstream>
//#include<iterator>
int main()
{
  std::ifstream fin("input.txt");
  std::ofstream fout("output.txt");
  
  std::string s;
  int para, ans = 0;
  std::multiset<int> gen;
  std::multiset<int>::iterator it;

  fin >> s;
  for (int i = 1; i < s.size(); i++) 
  {
    para = ((int)(s[i - 1] - 'A')) * 26 + (int)(s[i] - 'A');
    gen.insert(para);
  }
  fin >> s;
  for (int i = 1; i < s.size(); i++)
  {
    para = ((int)(s[i - 1] - 'A')) * 26 + (int)(s[i] - 'A');
    ans += gen.count(para);
    gen.erase(para);
  }
  fout << ans;
}