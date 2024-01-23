#include <iostream>
#include <filesystem>
#include <string>
using namespace std;
using namespace std::filesystem;

int main()
{
   string basis{"C:/Temp"};
   // string basis{"/home/theis/Temp"};
   // path element{basis + "/a.txt"};
   path element{basis + "/unter"};
   
   if(!exists(element))
      return 1;

   cout << "Pfad:        " << element << endl;
   cout << "Verzeichnis: " << element.parent_path() << endl;
   cout << "Ganzer Name: " << element.filename() << endl;
  
   cout << "Pfadteile:   ";
   for(const auto& teil : element)
      cout << teil << " ";
   cout << endl;

   if(is_regular_file(element))
   {
      cout << "Pfad zu Datei" << endl;
      cout << "Name:        " << element.stem() << endl;
      cout << "Erweiterung: " << element.extension() << endl;
      cout << "Byte:        " << file_size(element) << endl; 
   }
   else if(is_directory(element))
      cout << "Pfad zu Verzeichnis" << endl;

   path da{current_path()};
   da.append("hallo");
   da.concat(".cpp");
   cout << "Pfad:        " << da << endl;
}

