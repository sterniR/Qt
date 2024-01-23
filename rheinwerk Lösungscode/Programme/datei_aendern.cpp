#include <iostream>
#include <filesystem>
#include <string>
using namespace std;
using namespace std::filesystem;

void dateiListe(const path& pfad)
{
   for(const directory_entry& de : directory_iterator(pfad))
      if(is_regular_file(de))
         cout << de.path().filename() << " ";
   cout << endl;
}

int main()
{
   string basis{"C:/Temp"};
   // string basis{"/home/theis/Temp"};

   dateiListe(basis + "/unter");

   copy_file(basis + "/b.txt", basis + "/unter/f.txt");
   dateiListe(basis + "/unter");

   rename(basis + "/unter/f.txt",
      basis + "/unter/ganzunter/g.txt");
   dateiListe(basis + "/unter");
   dateiListe(basis + "/unter/ganzunter");

   remove(basis + "/unter/ganzunter/g.txt");
   dateiListe(basis + "/unter/ganzunter");
}
