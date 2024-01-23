#include <iostream>
#include <filesystem>
using namespace std;
using namespace std::filesystem;

void verzeichnisListeRekursiv(const path& pfad)
{
   for(const directory_entry& de : directory_iterator(pfad))
   {
      cout << de.path() << endl;
      if(is_directory(de.path()))
         verzeichnisListeRekursiv(de.path());
   }
}
 
int main()
{
   path verzeichnis{"C:/Temp"};
   // path verzeichnis{"/home/theis/Temp"};
   
   cout << "Verzeichnis:" << endl;
   for(const directory_entry& de : directory_iterator(verzeichnis))
      cout << de.path() << endl;

   cout << endl;
   cout << "Verzeichnis-Hierarchie:" << endl;
   verzeichnisListeRekursiv(verzeichnis);
}
