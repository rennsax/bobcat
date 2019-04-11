#include <iostream>

#include <bobcat/datetime>

using namespace std;
using namespace FBB;

int main()
{
    DateTime utc{ time(0), DateTime::UTC };
    cout << utc << ", dst = " << utc.dst() << '\n';

    DateTime utcCopy{ utc };
    cout << utcCopy << '\n';


    DateTime local{ DateTime::LOCALTIME };
    cout << local << ", dst = " << local.dst() << '\n';

    DateTime localCopy{ local };
    cout << localCopy << '\n';

    DateTime moved{ std::move(localCopy) };
    cout << moved << ", dst = " << moved.dst() << '\n';

}

