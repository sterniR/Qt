#include <iostream>
#include <filesystem>
#include <string>

void verzeichnisListe(const std::filesystem::path &pfad)
{
    for(const std::filesystem::directory_entry &de : std::filesystem::directory_iterator(pfad))
    {
        if(std::filesystem::is_directory(de))
            std::cout << de.path().filename() << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::string basis {"/home/roman/Templates"};

    verzeichnisListe(basis);

    std::filesystem::create_directories(basis + "/verz");
    std::filesystem::copy_file(basis + "/b.txt", basis + "/verz/f.txt");
    verzeichnisListe(basis);

    std::filesystem::rename(basis + "/verz", basis + "/unter/verz_neu");
    verzeichnisListe(basis);
    verzeichnisListe(basis + "/unter");

    std::filesystem::remove(basis + "/unter/verz_neu/f.txt");
    std::filesystem::remove(basis + "/unter/verz_neu");
    verzeichnisListe(basis + "/unter");
}
