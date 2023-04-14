#include<string>
#include<iostream>
#include<set>
#include<fstream>
#include<map>

std::string to_low(std::string s)
{
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
    {
      s[i] = std::tolower(s[i]);
    }
  }
  return s;
}

char is_char(char ch, bool reg, bool num, bool fst)
{
  if ((num == true || fst == false) && (ch >= '0') && (ch <= '9')) return ch;
  else if ((ch >= '0') && (ch <= '9') && num == false && fst == true) return 1;
  else if ((ch >= 'A' && ch <= 'Z'))
  {
    if (reg == false) return tolower(ch);
    else return ch;
  }
  else if ((ch >= 'a' && ch <= 'z')) return ch;
  else if (ch == '_') return ch;
  else
  {
    //std::cout << "ERROR_INis_char!"<< ch << '!';
    return ' '; // пробел = символ отпадает
  }
}

bool is_key(std::string s, std::set<std::string>* p_key, bool reg)
{
  std::set<std::string>::iterator it;
  if (reg == false)
  {
    s = to_low(s);
  }
  for (it = p_key->begin(); it != p_key->end(); it++)
  {
    if (p_key->find(s) != p_key->end()) return true;
  }
  return false;
}

int main()
{

  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);

  bool reg, num, fst = 1, not_number = false;
  std::string s1, ans, s2, s, new_word;
  int n, mx = 0, order_num = 1;
  std::set<std::string> key;
  std::map<std::string, int> ident;
  std::string order[10000];
  fin >> n >> s1 >> s2;
  if (s1 == "yes") reg = true;
  else if (s1 == "no") reg = false;
  //else std::cout << "error";

  if (s2 == "yes") num = true;
  else if (s2 == "no") num = false;
  //else std::cout << "error";

  for (int i = 0; i < n; i++)
  {
    fin >> s;
    if (reg == false) s = to_low(s);
    key.insert(s);
  }
  char new_char;
  while (!fin.eof())
  {
    new_char = fin.get();
    new_char = is_char(new_char, reg, num, fst);
    //std::cout << 'a';
    //std::cout << new_char << ' ';
    if (new_char == 1)
    {
      while (new_char != ' ')
        new_char = is_char(fin.get(), reg, num, fst);
      fst = true;
      not_number = false;
    }
    else if (new_char != ' ')
    {
      new_word.push_back(new_char);
      if (new_char > '9' || new_char < '0')
        not_number = true;
      fst = false;
    }
    else if (not_number == false)
    {
      fst = true;
      not_number = false;
      new_word = "";
    }
    else if (new_word != "")
    {
      fst = true;
      if (key.find(new_word) == key.end()) 
      {
        if (ident.find(new_word) == ident.end())
        {
          ident.insert(std::pair<std::string, int>(new_word, 0));
          order[order_num] = new_word;
          order_num++;
        }
        ident[new_word]++;
        if (ident[new_word] > mx)
        {
          mx = ident[new_word];
          ans = new_word;
        }
        else if (ident[new_word] == mx)
        {
          int ord_ans, ord_new;
          for (int i = 0; i < order_num; i++)
          {
            if (order[i] == ans)
              ord_ans = i;
            if (order[i] == new_word)
              ord_new = i;
          }
          if(ord_new < ord_ans)
            ans = new_word;
        }
        //std::cout << new_word << std::endl;
      }
      new_word = "";
      not_number = false;
    }
    //fout << is_char(new_char, reg, num, fst) << ' ';
  }
  fout << ans;
  //fout << ' ' << mx;
  //fout << ident["VeAF5SCB51X6UWM9xcn4Bw7TKlIjazfXhC3Cq"];
}

