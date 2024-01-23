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
   create_directory(basis + "/verz/verz_unter");
   verzeichnisListe(basis);
   
   path von{basis + "/verz"}; 
   copy(von, basis + "/verz_kopie", copy_options::recursive);
   verzeichnisListe(basis);
   
   rename(basis + "/verz_kopie", basis + "/verz_neu");
   verzeichnisListe(basis);
   
   remove_all(basis + "/verz");
   remove_all(basis + "/verz_neu");
   verzeichnisListe(basis);
}
