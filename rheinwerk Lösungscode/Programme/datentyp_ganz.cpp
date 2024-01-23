#include <iostream>
#include <climits>
using namespace std;
int main()
{
   cout << "short: " << sizeof(short) << " Byte, ";
   cout << "von " << SHRT_MIN << " bis " << SHRT_MAX << endl;

   cout << "unsigned short: "
      << sizeof(unsigned short) << " Byte, ";
   cout << "von 0 bis " << USHRT_MAX << endl;

   cout << "int: " << sizeof(int) << " Byte, ";
   cout << "von " << INT_MIN << " bis " << INT_MAX << endl;
   int a = 42;

   cout << "unsigned int: " << sizeof(unsigned int) << " Byte, ";
   cout << "von 0 bis " << UINT_MAX << endl;
   unsigned int b = 42U;

   cout << "long: " << sizeof(long) << " Byte, ";
   cout << "von " << LONG_MIN << " bis " << LONG_MAX << endl;
   long c = 42L;

   cout << "unsigned long: " << sizeof(unsigned long) << " Byte, ";
   cout << "von 0 bis " << ULONG_MAX << endl;
   unsigned long d = 42UL;

   cout << "long long: " << sizeof(long long) << " Byte, ";
   cout << "von " << LLONG_MIN << " bis " << LLONG_MAX << endl;
   long long e = 42LL;

   cout << "unsigned long long: "
      << sizeof(unsigned long long) << " Byte, ";
   cout << "von 0 bis " << ULLONG_MAX << endl;
   unsigned long long f = 42ULL;
   
   int x = 2'000'000'000;
   cout << "Viele Ziffern: " << x << endl;
}

