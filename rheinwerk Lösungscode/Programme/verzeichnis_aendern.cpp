#include <iostream>
#include <filesystem>
#include <string>
using namespace std;
using namespace std::filesystem;

void verzeichnisListe(const path& pfad)
{
   for(const directory_entry& de : directory_iterator(pfad))
      if(is_directory(de))
         cout << de.path().filename() << " ";
   cout << endl;
}

int main()
{
   string basis{"C:/Temp"};
   // string basis{"/home/theis/Temp"};

   verzeichnisListe(basis);
   
   create_directory(basis + "/verz");
   copy_file(basis + "/b.txt", basis + "/verz/f.txt");
   verzeichnisListe(basis);
   
   rename(basis + "/verz", basis + "/unter/verz_neu");
   verzeichnisListe(basis);
   verzeichnisListe(basis + "/unter");
   
   remove(basis + "/unter/verz_neu/f.txt");
   remove(basis + "/unter/verz_neu");
   verzeichnisListe(basis + "/unter");
}
