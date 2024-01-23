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

   if((status(datei).permissions() & perms::owner_write)
         != perms::none)
      cout << "Schreibrecht" << endl;

   permissions(datei, perms::owner_write,
      perm_options::remove);
   if(!((status(datei).permissions() & perms::owner_write)
         != perms::none))
      cout << "Kein Schreibrecht" << endl;

   permissions(datei, perms::owner_write,
      perm_options::add);
   if((status(datei).permissions() & perms::owner_write)
         != perms::none)
      cout << "Schreibrecht" << endl;
}
