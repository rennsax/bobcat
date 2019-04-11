#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime2 local{ DateTime2::LOCALTIME };

    cout << "local time: " << local << '\n';

    local.setMonth(DateTime2::Jun, DateTime2::THIS_YEAR);
    cout << "Jun this year: " << local << '\n';

    local.setMonth(DateTime2::Jun, DateTime2::LAST);
    cout << "Jun last year: " << local << '\n';

    local.setMonth(DateTime2::Jun, DateTime2::NEXT);
    cout << "Jun next year: " << local << '\n';
}
