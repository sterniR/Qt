#include <iostream>
#include <forward_list>
using namespace std;

void ausgeben(std::forward_list<int>& x)
{
    std::forward_list<int>::iterator position;
    for(position = x.begin(); position != x.end(); position++)
        std::cout << *position << " ";
    std::cout << '\n';
}

int main()
{
    std::forward_list<int> f;
    std::forward_list<int>::iterator position;

    for(int i=0; i<5; i++)
        f.push_front(10 * (i+1));
    std::cout << "push_front():   ";
    ausgeben(f);

    f.pop_front();
    std::cout << "pop_front():    ";
    ausgeben(f);

    position = f.begin();
    f.insert_after(position, 77);
    std::cout << "insert_after(): ";
    ausgeben(f);

    position = f.begin();
    f.erase_after(position);
    std::cout << "erase_after():  ";
    ausgeben(f);
    std::cout << '\n';

    f.sort();
    std::cout << "sort():         ";
    ausgeben(f);

    std::forward_list<int> fZwei{10,20,60,70};
    std::cout << "Andere Liste:   ";
    ausgeben(fZwei);
    f.merge(fZwei);
    std::cout << "merge():        ";
    ausgeben(f);
    std::cout << "Andere Liste:   ";
    ausgeben(fZwei);
    std::cout << '\n';

    f.unique();
    std::cout << "unique():       ";
    ausgeben(f);

    fZwei = {10,40,40};
    std::cout << "Andere Liste:   ";
    ausgeben(fZwei);
    position = f.begin();
    position++;
    f.splice_after(position, fZwei);
    std::cout << "splice_after(): ";
    ausgeben(f);
    std::cout << "Andere Liste:   ";
    ausgeben(fZwei);
    std::cout << '\n';

    f.remove(40);
    std::cout << "remove():       ";
    ausgeben(f);

    f.reverse();
    std::cout << "reverse():      ";
    ausgeben(f);

    f.clear();
    std::cout << "clear():        ";
    ausgeben(f);

    std::forward_list fd{16,15,14};
    std::cout << "Deduktion:      ";
    ausgeben(fd);





}
