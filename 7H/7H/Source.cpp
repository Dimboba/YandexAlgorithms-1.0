//#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<set>

struct point
{
  int time;
  int second_time;
  int person;
  char type;
  point(int time1, int person1, int second_time1, char type1) :time(time1), person(person1), second_time(second_time1), type(type1) {}
  bool operator<(const point& sec)
  {
    if (time != sec.time)
      return time < sec.time;
    else if(type != sec.type)
      return type > sec.type;
    else
    {
      if (type == 'b')
      {
        return second_time > sec.second_time;
      }
      else
        return second_time > sec.second_time;
    }
  }
};

bool security(std::ifstream &fin)
{
  int n, a, b, count = 0, last_man = -1;
  std::vector<point> vec;
  std::vector<bool> person;
  std::set<int> curr;
  fin >> n;
  for (int i = 0; i < n; i++)
  {
    fin >> a >> b;
    person.push_back(false);
    vec.push_back(point(a, i, b, 'b'));
    vec.push_back(point(b, i, a, 'e'));
  }

  sort(vec.begin(), vec.end());
  //std::cout << vec.size() << '!';
  if (vec[0].time > 0 || vec[vec.size() - 1].time < 10000)
    return false;
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i].type == 'b')
    {
      if (vec[i].time > 0)
      {
        if (count == 0 && vec[i - 1].time != vec[i].time)
          return false;
      }
      if (count == 1)
      {
        person[*curr.begin()] = true;
      }
      count++;
      curr.insert(vec[i].person);
    }
    if (vec[i].type == 'e')
    {
      if (count == 1)
      {
        person[*curr.begin()] = true;
      }
      count--;
      curr.erase(vec[i].person);
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (person[i] == false)
      return false;
  }
  return true;
}

int main()
{
  std::ifstream fin("input.txt", std::ios::in);
  int k;
  bool ka;
  fin >> k;
  for (int i = 0; i < k; i++)
  {
    ka = security(fin);
    if (ka == false)
      std::cout << "Wrong Answer";
    else if (ka == true)
      std::cout << "Accepted";
    std::cout << std::endl;
  }
}

