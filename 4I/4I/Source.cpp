#include<string>
#include<iostream>
#include<set>
#include<fstream>
//#include<iterator>

std::string to_low(std::string s)
{
  std::string ans = "";
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z') ans.push_back(s[i] + 32);
    else if (s[i] >= 'a' && s[i] <= 'z') ans.push_back(s[i]);
    else
      std::cout << "ERROR";
  }
  return ans;
}

int main()
{

  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);

  std::string s;
  int n, count = 0, ans = 0;
  std::set<std::string> dictionary, dictionary2;
  std::set<std::string>::iterator it;

  fin >> n;
  for (int i = 0; i < n; i++)
  {
    fin >> s;
    dictionary.insert(to_low(s));
    dictionary2.insert(s);
  }
  //getline(fin, s, '\n');

  while (!fin.eof())
  {
    fin >> s;
    if (s == "  ") continue;
    if ((dictionary.find(to_low(s))) == dictionary.end())
    {
      count = 0;
      for (int i = 0; i < s.size(); i++)
      {
        if (s[i] >= 'A' && s[i] <= 'Z')  count++;
        if (count > 1) break;
      }
      if (count == 0 || count > 1) 
      { 
        ans++;
        //std::cout << s;
      }
    }
    else 
    {
      if (dictionary2.find(s) == dictionary2.end())
      {
        //std::cout << s;
        ans++;
      }
    }
    s = "  ";
  }
  fout << ans;
}

