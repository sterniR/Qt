#include <iostream>
#include <filesystem>
#include <string>
using namespace std;
using namespace std::filesystem;

int main()
{
   string basis{"C:/Temp"};
   // string basis{"/home/theis/Temp"};
   path datei{basis + "/a.txt"};

   string vektor = "---------";
   perms pm = status(datei).permissions(); 
   if((pm & perms::owner_read) != perms::none)
      vektor.at(0) = 'r';
   if((pm & perms::owner_write) != perms::none)
      vektor.at(1) = 'w';
   if((pm & perms::owner_exec) != perms::none)
      vektor.at(2) = 'x';
   if((pm & perms::group_read) != perms::none)
      vektor.at(3) = 'r';
   if((pm & perms::group_write) != perms::none)
      vektor.at(4) = 'w';
   if((pm & perms::group_exec) != perms::none)
      vektor.at(5) = 'x';
   if((pm & perms::others_read) != perms::none)
      vektor.at(6) = 'r';
   if((pm & perms::others_write) != perms::none)
      vektor.at(7) = 'w';
   if((pm & perms::others_exec) != perms::none)
      vektor.at(8) = 'x';
   cout << "Zugriffsrechte: " << vektor << endl;
}
