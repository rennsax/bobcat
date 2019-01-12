#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
//    string zone{ DateTime::zone(DateTime::zone() / 60) };
//    cout << "Info: local zone shift: " << zone << "\n\n";

    string date{ "Mon Dec 3 13:29:11 2018" };

    DateTime utc{ date };
    DateTime local{ date, DateTime::LOCALTIME };

    cout << "Info: input time = " << date << " (no zone specification)\n"
            "       as utc (same): " << utc << "\n"
            "as local time (same): " << local << ", DST = " << 
                                                        local.dst() << "\n"
            "      its utc (-1 hr.): " << local.utc() <<"\n\n";

    date = "Mon Jul 3 13:29:11 2018";
    DateTime utc2{ date };
    DateTime local2{ date, DateTime::LOCALTIME };

    cout << "Info: input time = " << date << " (no zone specification)\n"
            "       as utc (same): " << utc2 << "\n"
            "as local time (same): " << local2 << ", DST = " << 
                                                        local2.dst() << "\n"
            "      its utc (-2 hr.): " << local2.utc() <<"\n\n";
}









