#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime local{ DateTime::LOCALTIME };

    cout << "local time: " << local << "\n\n";

    local.setMonth(DateTime::JANUARY);

    cout << "Jan: " << local << ", DST = " << local.dst() << "\n\n";

    local.setMonth(DateTime::JULY);

    cout << "July: " << local << ", DST = " << local.dst() << "\n\n";

}
