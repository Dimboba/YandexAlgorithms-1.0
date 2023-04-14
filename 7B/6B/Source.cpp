//#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
//#include<map>

struct point
{
  int num;
  char type;
  int order;

  point(int nm, char tp, int ord = -1)
  {
    num = nm;
    type = tp;
    order = ord;
  }
  bool operator <(const point& sec)
  {
    if(num != sec.num)
      return num < sec.num;
    else
    {
      return type < sec.type;
    }
  }
};

int main()
{
  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);
  int n, m, b, e, count = 0;
  std::vector<point> vec;

  fin >> n >> m;
  int* ans = new int[m];
  for (int i = 0; i < n; i++)
  {
    fin >> b >> e;
    //if (b < mn) mn = b;
    //if (e > mx) mx = e;
    vec.push_back(point(b, 'b'));
    vec.push_back(point(e, 'e'));
  }
  for (int i = 0; i < m; i++)
  {
    fin >> b;
    //if (b < mn) mn = b;
    //if (b > mx) mx = b;
    vec.push_back(point(b, 'd', i));
    //std::cout << b << ' ' << i<<std::endl;
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < m + 2*n; i++)
  {
    //std::cout << i << ' ' << vec[i].type << ' ' << vec[i].order << "  " << count<<std::endl;
    if (vec[i].type == 'b') count++;
    else if (vec[i].type == 'd')
    {
      ans[vec[i].order] = count;
    }
    else if (vec[i].type == 'e') count--;
  }
  for (int i = 0; i < m; i++)
  {
    fout << ans[i] << ' ';
  }
}

