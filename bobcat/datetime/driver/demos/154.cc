#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    string zone{ DateTime2::zoneTxt(DateTime2::defaultZoneMinutes()) };
    cout << "Info: local zone: " << zone << "\n"
            "      CET zone: " << 
                   DateTime2::zoneTxt(DateTime2::minutes("CET")) << "\n\n";


    string date{ "2018-12-03 13:29:11+01:00" };
    DateTime2 local{ date, 120 };
    cout << "Info: input time " << date << "\n"
            "as local time (UTC +2 hr.): " << local << 
                                            ", DST = " << local.dst() << "\n"
            "      its utc (-2 hr.): " << local.utc() <<"\n\n";

    date = "2018-07-03 13:29:11+01:00"  ;
    DateTime2 local2{ date, 120 };
    cout << "Info: input time = " << date << "\n"
            "as local time (also 14:29:11, as DST is suppressed):\n" << 
            "     " << local2 << ", DST = " << local2.dst() << "\n"
            "      its utc (-2 hr.): " << local2.utc() <<"\n\n";


    DateTime2 local3{ date, 120, 
                    DateTime2::DSTSpec{ true } };
    cout << "Info: input time = " << date << "\n"
            "as local time (15:29:11, as DST is SUPPORTED):\n" << 
            "     " << local3 << ", DST = " << local3.dst() << "\n"
            "      its utc (-3 hr.): " << local2.utc() <<"\n\n";
}









