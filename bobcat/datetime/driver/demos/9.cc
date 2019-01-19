#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    tm ts = 
    {
        0,
        0,
        12,                 // hr
        10,                 // daynr
        2,                  // month
        2018                 // year
    };

    DateTime utc{ ts };
    cout << "\nInfo: struct tm at utc Mar 10, 12:00, 2018:\n"
            "utc: " << utc << "\n\n";

    DateTime local{ ts, DateTime::LOCALTIME };

//    string zone{ local.zone(local.zone() / 60) };
//    cout << "Info: current zone shift: " << zone << "\n"
//                                                    "for UTC: subtract " << 
//                                                                zone << "\n";

    cout << "      tm at local time Mar 10, 12:00, 2018;\n"
            "local time: " << local << ", DST = " << local.dst() << "\n"
            "   its utc: " << local.utc() <<"\n\n";

    ts.tm_mon = 6;                                      // July

    DateTime utc2{ ts };                                // default: UTC
    cout << "Info: tm at UTC Jul 10, 12:00, 2018\n"
            "utc: " << utc2 << "\n\n";

    DateTime local2{ ts, DateTime::LOCALTIME };
    cout << "Info: tm at LOCAL time Jul 10, 12:00, 2018\n"
            "local time: " << local2 << ", DST = " << local2.dst() << "\n"
            "   its utc: " << local2.utc() <<"\n\n";
}



