#include <iostream>
using namespace std;
int main()
{
   #ifdef __unix__
      cout << "Unix / Linux" << endl;
   #elif __APPLE__
      cout << "Apple" << endl;
   #elif __WIN32__
      cout << "Win32" << endl;
   #endif
}

