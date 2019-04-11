#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime utc;
    cout << "UTC: " << utc << '\n';

    DateTime dt1{ time(0) + 3600, 
                  chrono::hours{ 3 } };  // no DST, local time: utc + 1 + 3 hrs
    cout << "no DST, local time UTC + 4 hours: " << dt1 << '\n';
}

