// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful


template<class T, class U>
void read_file_to_cont(std::ifstream& f, U& c)
{
  T elm;
  while (f >> elm)
    c.push_back(elm);
}


template<class T ,class U>
void read_and_sort(std::ifstream& fin, std::ofstream& fout) {

  U container = {};
  read_file_to_cont<T, U>(fin, container);
  my_selection_sort(container.begin(), container.end());

  for (T& elm : container)
    fout << elm << std::endl;
}


template<class T>
void read_and_sort_decide_container(std::ifstream& fin, std::ofstream& fout) {
  char line;
  fin >> line;
  fout << line << "\n";

  switch(line)
  {
    case 'l':
      read_and_sort<T, std::list<T>>(fin, fout);
      break;

    case 'v':
      read_and_sort<T, std::vector<T>>(fin, fout);
      break;

    case 'd':
      read_and_sort<T, std::deque<T>>(fin, fout);
      break;
  }
}


void read_and_sort_decide_valuetype(std::ifstream& fin, std::ofstream& fout) {
  char line;
  fin >> line;
  fout << line << "\n";

  switch(line)
  {
    case 'i':
      read_and_sort_decide_container<int>(fin, fout);
      break;

    case 'u':
      read_and_sort_decide_container<unsigned>(fin, fout);
      break;

    case 'f':
      read_and_sort_decide_container<float>(fin, fout);
      break;

    case 'd':
      read_and_sort_decide_container<double>(fin, fout);
      break;

    case 'c':
      read_and_sort_decide_container<char>(fin, fout);
      break;

    case 's':
      read_and_sort_decide_container<std::string>(fin, fout);
      break;
  }
}