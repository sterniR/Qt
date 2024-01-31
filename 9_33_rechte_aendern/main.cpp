#include <iostream>
#include <filesystem>
#include <string>

int main()
{
    std::string basis {"/home/roman/Templates"};
    std::filesystem::path datei {basis + "/a.txt"};

    if((std::filesystem::status(datei).permissions() & std::filesystem::perms::owner_write) != std::filesystem::perms::none)
        std::cout << "Schreibrecht: " << '\n';

    std::filesystem::permissions(datei, std::filesystem::perms::owner_write, std::filesystem::perm_options::remove);
    if((std::filesystem::status(datei).permissions() & std::filesystem::perms::owner_write) == std::filesystem::perms::none)
        std::cout << "Kein Schreibrecht: " << '\n';

    std::filesystem::permissions(datei, std::filesystem::perms::owner_write, std::filesystem::perm_options::add);
    if((std::filesystem::status(datei).permissions() & std::filesystem::perms::owner_write) != std::filesystem::perms::none)
        std::cout << "Schreibrecht: " << '\n';
}
