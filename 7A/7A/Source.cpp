#include<string>
#include<iostream>
//#include<vector>
//#include<cmath>
#include<fstream>
#include<map>

int main()
{
  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);
  int n, m, b, e, curr = 0, watched = 0, last;
  std::multimap<int, int> events;
  std::multimap<int, int>::iterator it;
  fin >> n >> m;
  for (int i = 0; i < 2 * m; i += 2)
  {
    fin >> b >> e;
    events.insert(std::pair<int, int>(b, 1));
    events.insert(std::pair<int, int>(e+1, -1));
  }
  for (it = events.begin(); it != events.end(); it++)
  {
    //fout << it->first << ' ' << it->second << '\n';
    if (curr > 0)
    {
      watched += it->first - last;
      std::cout << last << ' ' << it->first << ' ' << watched << std::endl;
    }
    //if (curr == 1 && it->second == -1) watched++;
    if (it->second == 1)
      curr++;
    else if (it->second == -1)
      curr--;
    last = it->first;
  }
  fout << n-watched;
  /*
  std::pair<int,int>* events = new std::pair<int,int>[2*m+1];
  fin >> n >> m;
  for (int i = 0; i < 2*m; i+=2)
  {
    fin >> b >> e;
    events[i].first = b;
    events[i].second = 1;
    events[i + 1].first = e;
    events[i + 1].second = -1;
  }
  for (int i = 0; i < 2 * m; i++)
    std::cout << events[i].first << ' ' << events[i].second << std::endl;
  std::cout << std::endl;
  for (int i = 0; i < 2 * m; i++)
  {
    if (curr > 0)
    {
      watched += events[i].first - events[i - 1].first;
      std::cout << i << ' ' << events[i].first << ' ' << events[i - 1].first << ' ' << watched << std::endl;
    }
    if (events[i].second == 1)
      curr++;
    else if (events[i].second == -1)
      curr--;
  }
  */
}

