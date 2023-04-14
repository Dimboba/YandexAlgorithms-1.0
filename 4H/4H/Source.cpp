#include<string>
#include<iostream>
#include<map>
#include<fstream>
//#include<iterator>


int main()
{

  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);

  std::string w, s;
  int word_length, full_length, ans = 0;
  std::map<char, int> num, curr;
  std::map<char, int>::iterator it;
  bool ka = true;

  fin >> word_length >> full_length;
  fin >> w >> s;
  for (int i = 0; i < w.length(); i++)
  {
    if (num.find(w[i]) == num.end())
      num.insert(std::pair<char, int> (w[i], 0));
    num[w[i]]++;
    //std::cout << w[i]<<num[w[i]];
  }
  curr = num;
  for (int i = 0; i < s.length(); i++)
  {
    //std::cout << i << std::endl;
    for (int j = 0; j < w.length(); j++)
    {
      //std::cout << s[j + i] << ' ' << num[s[j + i]] << ' ' << curr[s[j + i]] << std::endl;
      if (num.find(s[j + i]) == num.end() || curr[s[j + i]] <= 0)
      {
        //std::cout << "false";
        ka = false;
        break;
      }
      curr[s[j + i]]--;
    }
    if (ka == true) ans++;
    curr = num;
    ka = true;
  }
  fout << ans;
}

