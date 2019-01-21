#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime local{ DateTime::LOCALTIME };

    cout << "local time: " << local << '\n';

    local.setMonth(DateTime::Jun, DateTime::THIS_YEAR);
    cout << "Jun this year: " << local << '\n';

    local.setMonth(DateTime::Jun, DateTime::LAST);
    cout << "Jun last year: " << local << '\n';

    local.setMonth(DateTime::Jun, DateTime::NEXT);
    cout << "Jun next year: " << local << '\n';
}
