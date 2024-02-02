#include <iostream>
#include <filesystem>
#include <string>

void dateiListe(const std::filesystem::path &pfad)
{
    for(const std::filesystem::directory_entry &de : std::filesystem::directory_iterator(pfad))
    {
        if(std::filesystem::is_regular_file(de))
            std::cout << de.path().filename() << " ";
        std::cout << '\n';
    }
}

int main()
{
    std::string basis{"/home/roman/Templates"};

    dateiListe(basis + "/unter");

    std::filesystem::copy_file(basis + "/b.txt", basis + "/unter/f.txt");
    dateiListe(basis + "/unter");

    std::filesystem::rename(basis + "/unter/f.txt", basis + "/unter/ganzunter/g.txt");
    dateiListe(basis + "/unter");
    dateiListe(basis + "/unter/ganzunter");


}

