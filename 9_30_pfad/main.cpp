#include <iostream>
#include <filesystem>
#include <string>

int main()
{
    std:: string basis{"/home/roman/Templates"};
    std::filesystem::path element{basis + "/a.txt"};
    //std::filesystem::path element{basis + "/unter"};
    if(!std::filesystem::exists(element))
        return 1;

    std::cout << "Pfad:        " << element << '\n';
    std::cout << "Verzeichnis: " << element.parent_path() << '\n';
    std::cout << "Ganzer Name: " << element.filename() << '\n' << '\n';

    std::cout << "Pfadteile    ";
    for (const std::filesystem::path& teil:element)
        std::cout << teil << " ";
    std::cout << '\n' << '\n';

    if(std::filesystem::is_regular_file(element))
    {
        std::cout << "Pfad zu Datei:" << '\n';
        std::cout << "Name:         " << element.stem() << '\n';
        std::cout << "Erweiterung:  " << element.extension() << '\n';
        std::cout << "Byte:         " << file_size(element) << '\n' << '\n';
    }
    else if(std::filesystem::is_directory(element))
    {
        std::cout << "Pfad zu Verzeichnis" << '\n';
    }

    std::filesystem::path da{std::filesystem::current_path()};
    da.append("hallo");
    da.concat(".cpp");
    std::cout << "Pfad:        " << da << '\n';
}
