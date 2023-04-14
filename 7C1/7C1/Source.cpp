//#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<map>

int compare(const void* a, const void* b)
{
  return (*(int*)a - *(int*)b);
}
struct student
{
  int coord; 
};

int main()
{
  std::ifstream  fin("input.txt", std::ios::in);
  std::ofstream  fout("output.txt", std::ios::out);

  
  int n, dist, nw, count = 0, mx = 0;
  fin >> n >> dist;
  int* mass = new int[n];
  for (int i = 0; i < n; i++)
  {
    fin >> mass[i];
  }
  qsort(mass, n, sizeof(int), compare);
  for (int i = 0; i < n; i++)
  {
    
  }
}

