#include <iostream>
#include <tuple>
#include <string>

int main()
{
    std::tuple<int,std::string,int,double> ta;
    ta = std::tuple<int,std::string,int,double>(5, "Berlin", 42, 7.52);
    std::cout << std::get<0>(ta) << " " << std::get<1>(ta) << " "
              << std::get<2>(ta) << " " << std::get<3>(ta) << " " << '\n';
    std::cout << std::get<std::string>(ta) << " " << std::get<double>(ta) << '\n';

    int x,y;
    std::string s;
    double d;
    std::tie(x,s,y,d) = ta;
    std::cout << x << " " << s << " " << y << " " << d << '\n' << '\n';


    std::tuple<int,std::string,int,double> tb;
    tb = std::make_tuple(7, "Dortmund", 72, 1.51);
    std::cout << std::get<0>(tb) << " " << std::get<1>(tb) << " "
              << std::get<2>(tb) << " " << std::get<3>(tb) << '\n' << '\n';

    std::tuple<int, std::string> tc;
    tc =std::make_tuple(12, "Hamburg");

    std::tuple<int,double> td;
    td = std::make_tuple(4, 3.85);

    std::tuple<int, std::string,int, double> te;
    te = std::tuple_cat(tc, td);
    std::cout << std::get<0>(te) << " " << std::get<1>(te) << " "
              << std::get<2>(te) << " " << std::get<3>(te) << '\n' << '\n';

    std::tuple tf{8, "Stuttgart", 38, 4.91};
    std::cout << std::get<0>(tf) << " " << std::get<1>(tf) << " "
              << std::get<2>(tf) << " " << std::get<3>(tf) << '\n' << '\n';
}
