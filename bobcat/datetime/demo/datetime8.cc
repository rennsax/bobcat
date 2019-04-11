#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime utc;
    cout << "UTC: " << utc << '\n';

                                        // no DST, local time: utc + 3 hrs
    DateTime dt1{ DateTime::Zone{ "3" } };            // via 5.f to 8
    cout << "3 hours later: " << dt1 << '\n';

    DateTime dt2{ chrono::hours{ 3 } };                // same, via 4.f to 8
    cout << "same: " << dt2 << '\n';

    DateTime dt3{ time(0) + 7 * 24 * 3600,             // one week later
                    chrono::hours{ 3 } };               
    cout << "one week later: " << dt3 << '\n';

    DateTime dt4{ DateTime::Zone{ "3", "1" } };       // via 5.f to 8
    cout << "3 hrs later + dst (1 hr) " << dt4 << '\n';

}

