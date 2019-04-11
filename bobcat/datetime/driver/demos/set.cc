#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime2 local{ DateTime2::LOCALTIME };

    cout << "local time: " << local << "\n\n";

    local.setMonth(DateTime2::JANUARY);

    cout << "Jan: " << local << ", DST = " << local.dst() << "\n\n";

    local.setMonth(DateTime2::JULY);

    cout << "July: " << local << ", DST = " << local.dst() << "\n\n";

}
