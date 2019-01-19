#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime local{::time(0), DateTime::LOCALTIME };
    
    cout << "\nCurrent local time:\n"
            "local time: " << local << "\n"
            "   its utc: " << local.utc() <<"\n\n";

    DateTime july{ (7 * 365 - 3) * 24 * 3600 + 6 * 31 * 24 * 3600,
                   DateTime::LOCALTIME };
    
    cout << "July, 7 years after the beginning of the epoch:\n"
            "local time: " << july << "\n"
            "   its utc: " << july.utc() << "\n\n";

    cout << "\nASSIGNING: local =  july:\n\n";
    local = july;

    cout << "Same as July 7, now using the first object:\n"
            "local time: " << local << "\n"
            "   its utc: " << local.utc() << "\n\n";
    
}

