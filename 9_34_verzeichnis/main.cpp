#include <iostream>
#include <filesystem>

void verzeichnisListeRekursiv(const std::filesystem::path &pfad)
{
    for(const std::filesystem::directory_entry & de : std::filesystem::directory_iterator(pfad))
    {
        std::cout << de.path() << '\n';
        if(std::filesystem::is_directory(de.path()))
            verzeichnisListeRekursiv(de.path());
    }
}

int main()
{
    std::filesystem::path verzeichnis {"/home/roman/Templates"};

    std::cout << "Verzeichnis: " << '\n';
    for(const std::filesystem::directory_entry & de : std::filesystem::directory_iterator(verzeichnis))
    {
        std::cout << de.path() << '\n';
    }
    std::cout << '\n';
    std::cout << "Verzeichnis-Hierarchie" << '\n';
    verzeichnisListeRekursiv(verzeichnis);
}
