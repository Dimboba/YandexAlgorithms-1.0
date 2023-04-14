//#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<set>

struct point
{
  int time;
  char type;
  point(int time1, char type1) :time(time1), type(type1) {}
  bool operator <(const point& sec)
  {
    if (time != sec.time)
    {
      return time < sec.time;
    }
    else
    {
      return type > sec.type;
    }
  }
};

int main()
{
  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);
  int n, a, b, c, d, count = 0, fulltime = 0, begin;
  std::vector<point> vec;
  fin >> n;
  for (int i = 0; i < n; i++)
  {
    fin >> a >> b >> c >> d;
    if (a * 60 + b < c * 60 + d)
    {
      vec.push_back(point(a * 60 + b, 'b'));
      vec.push_back(point(c * 60 + d, 'e'));
    }
    else
    {
      vec.push_back(point(a * 60 + b, 'b'));
      vec.push_back(point(24 * 60, 'e'));
      vec.push_back(point(0, 'b'));
      vec.push_back(point(c * 60 + d, 'e'));
    }
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i].type == 'b')
    {
      count++;
      if (count == n)
        begin = vec[i].time;
    }
    else if (vec[i].type == 'e')
    { 
      count--;
      if (count == n - 1)
        fulltime += vec[i].time - begin;
    }
  }
  std::cout << fulltime;
}

