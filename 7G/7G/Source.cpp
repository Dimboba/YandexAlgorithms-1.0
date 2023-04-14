//#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<set>

struct point
{
  int time;
  int person;
  point(int time1, int person1) :time(time1), person(person1) {}
  bool operator<(const point& sec)
  {
    if (time != sec.time)
      return time < sec.time;
    else
      return person < sec.person;
  }
};

int main()
{
  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);
  int m, n, t, z, y, count = 0, ans;
  std::vector<point> vec;
  std::vector<int> person;
  fin >> m >> n;
  for (int i = 0; i < n; i++)
  {
    fin >> t >> z >> y;
    person.push_back(0);  
    for (int j = 1; j <= m; j++)
    {
      vec.push_back(point((j * t + ((j - 1) / z) * y), i));
    }
  }
  sort(vec.begin(), vec.end());
  if (m == 0)
  {
    std::cout << 0 << std::endl;
    for (int i = 0; i < n; i++)
      std::cout << person[i] << ' ';
    return 0;
  }
  for (int i = 0; i < vec.size(); i++)
  {
    count++;
    person[vec[i].person]++;
    if (count == m)
    {
      ans = vec[i].time;
      break;
    }
  }
  std::cout << ans << std::endl;
  for (int i = 0; i < n; i++)
    std::cout << person[i] << ' ';
}

