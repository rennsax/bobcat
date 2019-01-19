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
        2018,
    };


    {
        cout << "Info: UTC to zone-minutes\n"
                "      zone-minutes determines the shift wrt UTC.\n"
                "      DST shifts are ignored,\n"
                "      struct tm at Mar 10, 12:00, 2018:\n\n";
    
        DateTime local{ ts, 60 };
        cout << "Info: zone +1 hr, local at 13:00, ts: UTC at 12:00\n"
                "local time: " << local << ", DST = " << local.dst() << "\n"
                "   its utc: " << local.utc() <<"\n\n";
    }

    ts.tm_mon = 6;          // July

    {
        DateTime local{ ts, 60 };
        cout << "Info: zone +1 hr, local at July 13:00, ts: UTC at 12:00\n"
                "local time: " << local << ", DST = " << local.dst() << "\n"
                "   its utc: " << local.utc() <<"\n\n";
    }


    {
        DateTime local{ ts, 60, DateTime::DSTSpec{ true } };
        cout << "Now supporting DST:\n"
                "Info: zone +1 hr, local at July 14:00, ts: UTC at 12:00\n"
                "local time: " << local << ", DST = " << local.dst() << "\n"
                "   its utc: " << local.utc() <<"\n\n";
    }

//
//    DateTime local2{ ts, 60 };
//    cout << "Info: zone +1 hr, tm at Jul 10, 12:00, 2018,\n"
//            "      local at 13:00, UTC at 12:00\n"
//            "local time: " << local2 << ", DST = " << local2.dst() << "\n"
//            "   its utc: " << local2.utc() <<"\n\n";
//
//
    ts.tm_mon = 2;          // March

    DateTime local3{ ts, 0 };
    cout << "Info: zone +0 hr, tm at Mar 10, 12:00, 2018,\n"
            "      local at 12:00, UTC at 12:00\n"
            "local time: " << local3 << ", DST = " << local3.dst() << "\n"
            "   its utc: " << local3.utc() <<"\n\n";

    ts.tm_mon = 6;          // July

//    {
//        DateTime local{ ts, DateTime::LOCALTIME };
//        cout << 
//                "Info: local at July, 12h, utc at 10h (zone = 1, dst = 1)\n"
//                "local time: " << local << ", DST = " << local.dst() << "\n"
//                "   its utc: " << local.utc() <<"\n\n";
//    }


    DateTime local4{ ts, 0 };
    cout << "Info: zone +0 hr, tm at Jul 10, 12:00, 2018,\n"
            "      local at 12:00, UTC at 12:00\n"
            "local time: " << local4 << ", DST = " << local4.dst() << "\n"
            "   its utc: " << local4.utc() <<"\n\n";
}




