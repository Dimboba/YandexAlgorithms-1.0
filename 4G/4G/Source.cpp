#include<string>
#include<iostream>
#include<map>
#include<fstream>
//#include<iterator>

std::ifstream  fin("input.txt", std::ios::in);
std::ofstream  fout("output.txt", std::ios::out);

void creation(std::map<std::string, int>* p_bank, std::string name)
{
  if (p_bank->find(name) == p_bank->end())
    p_bank->insert(std::pair<std::string, int>(name, 0));
}

void deposit(std::map<std::string, int>* p_bank, std::string name, int sum)
{
  creation(p_bank, name);
  p_bank->at(name) += sum;
}

void withdraw(std::map<std::string, int>* p_bank, std::string name, int sum)
{
  creation(p_bank, name);
  p_bank->at(name) -= sum;
}

void transfer(std::map<std::string, int>* p_bank, std::string sender, std::string reciever, int sum)
{
  deposit(p_bank, reciever, sum);
  withdraw(p_bank, sender, sum);
}

void income(std::map<std::string, int>* p_bank, int per)
{
  double coef = per + 100;
  coef /= 100;
  std::map<std::string, int>::iterator it;
  for (it = p_bank->begin(); it != p_bank->end(); it++)
  {
    if (it->second > 0)
      (it->second) *= coef;
  }
}

void balance(std::map<std::string, int>* p_bank, std::string name)
{
  if (p_bank->find(name) == p_bank->end()) 
    fout << "ERROR" << '\n';
  else 
    fout << p_bank->at(name)<< '\n';
}

void operation(std::map<std::string, int>* p_bank)
{
  std::string type = "   ", name1, name2;
  int sum;
  fin >> type;
  if (type == "   ") { return; }
  switch (type[0])
  {
  case 'D':
    fin >> name1 >> sum;
    deposit(p_bank, name1, sum);
    break;
  case 'W':
    fin >> name1 >> sum;
    withdraw(p_bank, name1, sum);
    break;
  case 'T':
    fin >> name1 >> name2 >> sum;
    transfer(p_bank, name1, name2, sum);
    break;
  case 'I':
    fin >> sum;
    income(p_bank, sum);
    break;
  case 'B':
    fin >> name1;
    balance(p_bank, name1);
    break;
  default:
    std::cout << "blyni";
  }
}

int main()
{
  std::string s = "    ";
  int n, k, nw;
  char ch;
  std::map<std::string, int> bank;
  while (!fin.eof())
  {
    operation(&bank);
  }
}

