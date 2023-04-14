//#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<map>

struct interval
{
  int num;
  int order;
  char type;
  interval(int number, char type, int order) : num(number), type (type), order(order) {}
  bool operator<(const interval& sec)
  {
    if (num != sec.num)
      return num < sec.num;
    return type < sec.type;
  }
};

int main()
{
  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);
  int n, dist, nw, count = 0, mx = 0;
  std::vector<interval> intervals;
  std::map<int, int> used;
  fin >> n >> dist;
  bool* vars = new bool[n + 1];
  int* ans = new int[n + 1];
  for (int i = 0; i < n + 1; i++)
  {
    vars[i] = false;
  }
  for (int i = 0; i < n; i++)
  {
    fin >> nw;
    intervals.push_back(interval(nw - dist, 'b', i));
    intervals.push_back(interval(nw, 'd', i));
    intervals.push_back(interval(nw + dist, 'e', i));
  }
  sort(intervals.begin(), intervals.end());
  for (int i = 0; i < 3 * n; i++)
  {
    if (intervals[i].type == 'b')
    {
      count++;
      for (int j = 1; j <= count; j++)
      {
        if (vars[j] == false)
        {
          vars[j] = true;
          used.insert(std::pair<int,int>(intervals[i].num + dist, j));
          ans[intervals[i].order] = j;
        }
      }
      //std::cout << std::endl;
    }
    else if (intervals[i].type == 'd')
    {
      //std::cout << intervals[i].order << ' ' << intervals[i].num << ' ' << count-1 << std::endl;
      if (count > mx) mx = count;
    }
    else if (intervals[i].type == 'e')
    {
      count--;
      vars[used[intervals[i].num - dist]] = false;
    }
  }
  fout << mx << '\n';
  for (int i = 0; i < n; i++)
  {
    fout << ans[i] << ' ';
  }
}

