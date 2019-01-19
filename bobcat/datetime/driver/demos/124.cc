#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    string zone{ DateTime::zoneTxt(DateTime::defaultZoneMinutes()) };
    cout << "Info: local zone: " << zone << "\n\n";

    string date{ "2018-12-03 13:29:11+01:00" };
    DateTime utc{ date };
    DateTime local{ date, DateTime::LOCALTIME };
    cout << "Info: time = " << date << "\n"
            "       as utc: " << utc << "\n"
            "as local time: " << local << ", DST = " << local.dst() << "\n"
            "      its utc: " << local.utc() <<"\n\n";

    date = "2018-07-03 13:29:11+01:00"  ;
    DateTime utc2{ date };
    DateTime local2{ date, DateTime::LOCALTIME };
    cout << "Info: time = " << date << "\n"
            "       as utc: " << utc2 << "\n"
            "as local time: " << local2 << ", DST = " << local2.dst() << "\n"
            "      its utc: " << local2.utc() <<"\n\n";
}
