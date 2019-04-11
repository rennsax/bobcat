#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime2 local{ DateTime2::LOCALTIME };
    DateTime2 copy{ local };

    cout << "local time: " << local << ", DST = " << local.dst() << "\n\n";

    local += 5 * 30 * 24 * 3600;        // add +/- 5 months;
    cout << "+/- 5 months. later: " << local << ", DST = " << local.dst() <<
                                                                    "\n\n"; 

    local = copy;
    cout << "Back to the initial time time: " << local << "\n\n";

    local += chrono::hours(-2);      // subtract two hours;
    cout << "2 hrs. earlier: " << local << ", DST = " << local.dst() <<
                                                                    "\n\n"; 

    local = copy;
    cout << "Back to the initial time time: " << local << "\n\n";

    local += tm {
                    +10,    // sec
                    +10,    // min
                     -5,    // hr
                      0,    // mday
                      5,    // month
                      1,    // year
                };

    cout << "10 sec, 10 min, 5 months 1 year later, 5 hrs earlier:\n" << 
            local << ", DST = " << local.dst() << "\n\n";

}

