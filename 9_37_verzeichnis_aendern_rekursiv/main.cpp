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
    std::string basis{"/home/roman/Templates"};

    verzeichnisListe(basis);

    std::filesystem::create_directories(basis + "/verz");
    std::filesystem::copy_file(basis + "/b.txt", basis + "/verz/f.txt");
    std::filesystem::create_directories(basis + "/verz/verz_unter");
    verzeichnisListe(basis);

    std::filesystem::path von{basis + "/verz"};
    std::filesystem::copy(von, basis + "/verz_kopie", std::filesystem::copy_options::recursive);
    verzeichnisListe(basis);
    verzeichnisListe(basis + "/verz");

    std::filesystem::rename(basis + "/verz_kopie", basis + "/verz_neu");
    verzeichnisListe(basis);

    std::filesystem::remove_all(basis + "/verz");
    std::filesystem::remove_all(basis + "/verz_neu");
    verzeichnisListe(basis);
}
