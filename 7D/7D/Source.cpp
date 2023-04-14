//#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<set>

struct point
{
  int time;
  char type; // b = вход e = последний момент когда покупатель может начать смотреть рекламу
  int num;
  point() :time(0), type('\0'), num(0) {}
  point(int time1, char type1, int num1) :time(time1), type(type1), num(num1) {}
  bool operator <(const point& sec)
  {
    if (time != sec.time)
      return time < sec.time;
    else
      return type < sec.type;
  }
};

int main()
{
  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);
  int n, mx2 = 0 , mx1 = 0, b, e, count = 0, num = 0, mxtime1 = -1, mxtime2 = -1;
  std::vector<point> vec;
  std::set<int>curr, ans;
  vec.resize(0);
  fin >> n;
  for (int i = 0; i < n; i++)
  {
    fin >> b >> e;
    if (e - b < 5) continue;
    vec.push_back(point(b, 'b', i));
    vec.push_back(point(e-5, 'e', i));
    //num += 2;
   // std::cout << vec.size() << ' ' << i << std::endl;
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i].type == 'b')
    {
      count++;
      curr.insert(vec[i].num);
    }
    if (count > mx1)
    {
      mx1 = count;
      mxtime1 = vec[i].time;
      ans = curr;
    }
    if (vec[i].type == 'e')
    {
      count--;
      curr.erase(vec[i].num);
    }
  }
  count = 0;
  //std::cout << mx1 << ' ' << mxtime << std::endl;
  for (int i = 0; i < vec.size(); i++)
  {
    if (ans.find(vec[i].num) != ans.end()) continue;
    if (vec[i].type == 'b')
    {
      count++;
      //curr.insert(i);
    }
    if (count > mx2 && std::abs(vec[i].time - mxtime1) >= 5 )
    {
      mx2 = count;
      mxtime2 = vec[i].time;
      //ans = curr;
    }
    if (vec[i].type == 'e')
    {
      count--;
      //curr.erase(i);
    }
  }
  //std::cout << mx2 << ' ' << mxtime << std::endl;
  std::cout << mx1 + mx2 << ' ';
  if (mxtime2 != -1)
    std::cout << std::min(mxtime2, mxtime1) << ' ' << std::max(mxtime1, mxtime2);
  else
    std::cout << mxtime1 << ' ' << mxtime1 + 10;

}

