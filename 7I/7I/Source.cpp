//#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<set>

struct point
{
  int city;
  int time;
  char type;
  point(int city1, int time1, char type1): city(city1), time(time1), type(type1) {}
  bool operator<(const point& sec)
  { 
    if (time != sec.time)
      return time < sec.time;
    else 
      return type > sec.type;
  }
};

int main()
{
  std::ifstream fin("input.txt", std::ios::in);
  std::vector<point> vec;
  int n, m;
  int f, x1, x2, g, y1, y2, ans = 0;
  char ch;
  fin >> n >> m;
  std::vector<int> check;
  std::vector<int> curr;
  curr.resize(n + 1, 0);
  check.resize(n + 1, 0);
  for (int i = 0; i < m; i++)
  {
    fin >> f >> x1 >> ch >> x2 >> g >> y1 >> ch >> y2;
    check[f]--;
    check[g]++;
    if (x1 * 60 + x2 < y1 * 60 + y2)
    {
      vec.push_back(point(f, x1 * 60 + x2, 'b'));
      vec.push_back(point(g, y1 * 60 + y2, 'e'));
    }
    else
    {
      vec.push_back(point(f, x1 * 60 + x2, 'b'));
      vec.push_back(point(0, 23 * 60 + 59, 'e'));
      vec.push_back(point(0, 0 * 60 + 0, 'b'));
      vec.push_back(point(g, y1 * 60 + y2, 'e'));

    }
      //std::cout << f << x1 << x2 << g << y1 << y2 << std::endl;
  }
  for (int i = 0; i <= n; i++)
  {
    if (check[i] != 0)
    {
      std::cout << -1;
      return 0;
    }
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++)
  {
    int curr_city = vec[i].city;
    if (vec[i].type == 'b')
    {
      if (curr[curr_city] <= 0)
      {
        ans++;
        curr[curr_city]++;
      }
      curr[curr_city]--;
    }
    else if (vec[i].type == 'e')
    {
      curr[curr_city]++;
    }
  }
  std::cout << ans;
}

