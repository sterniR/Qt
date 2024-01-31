#include <iostream>
#include <filesystem>
#include <string>

int main()
{
    std::string basis {"/home/roman/Templates"};
    std::filesystem::path datei {basis + "/a.txt"};

    std::string vektor = "--------";
    std::filesystem::perms pm = std::filesystem::status(datei).permissions();

    if((pm & std::filesystem::perms::owner_read) != std::filesystem::perms::none)
        vektor.at(0) = 'r';
    if((pm & std::filesystem::perms::owner_write) != std::filesystem::perms::none)
        vektor.at(1) = 'w';
    if((pm & std::filesystem::perms::owner_exec) != std::filesystem::perms::none)
        vektor.at(2) = 'x';

    if((pm & std::filesystem::perms::group_read) != std::filesystem::perms::none)
        vektor.at(3) = 'r';
    if((pm & std::filesystem::perms::group_write) != std::filesystem::perms::none)
        vektor.at(4) = 'w';
    if((pm & std::filesystem::perms::group_exec) != std::filesystem::perms::none)
        vektor.at(5) = 'x';

    if((pm & std::filesystem::perms::others_read) != std::filesystem::perms::none)
        vektor.at(6) = 'r';
    if((pm & std::filesystem::perms::others_write) != std::filesystem::perms::none)
        vektor.at(7) = 'w';
    if((pm & std::filesystem::perms::others_exec) != std::filesystem::perms::none)
        vektor.at(8) = 'x';

    std::cout << "Zugriffsrechte: " << vektor << '\n';
}
