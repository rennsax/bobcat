#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    string zone{ DateTime::zone(DateTime::zone() / 60) };
    cout << "Info: local zone shift: " << zone << "\n"
            "Using explicit zone shift +2 hr.\n\n";

    string date{ "2018-12-03 13:29:11+01:00" };
    DateTime local{ date, 120 };
    cout << "Info: input time " << date << "\n"
            "as local time (UTC +2 hr.): " << local << 
                                            ", DST = " << local.dst() << "\n"
            "      its utc (-2 hr.): " << local.utc() <<"\n\n";

    date = "2018-07-03 13:29:11+01:00"  ;
    DateTime local2{ date, 120 };
    cout << "Info: input time = " << date << "\n"
            "as local time (same): " << local2 << ", DST = " << 
                                                        local2.dst() << "\n"
            "      its utc (-2 hr.): " << local2.utc() <<"\n\n";
}









