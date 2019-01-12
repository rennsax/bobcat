#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime utc;
    DateTime local{ DateTime::LOCALTIME };

    cout << "local time:\n"
            "  utc time: " << utc << "\n"
            "local time: " << local << '\n';
}
