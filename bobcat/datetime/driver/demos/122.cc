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

    string date{ "Mon Dec 3 13:29:11 CET 2018" };

    DateTime2 utc{ date };
    DateTime2 local{ date, DateTime2::LOCALTIME };
    cout << "Info: time = " << date << "\n"
            "       as utc: " << utc << "\n"
            "Using CET zone minutes:\n"
            "as local time: " << local << ", DST = " << local.dst() << "\n"
            "      its utc: " << local.utc() <<"\n\n";

    date = "Mon Jul 3 13:29:11 CET 2018";
    DateTime2 utc2{ date };
    DateTime2 local2{ date, DateTime2::LOCALTIME };
    cout << "Info: time = " << date << "\n"
            "CET minutess 1 hour, so its UTC is at 12 hr. and its current\n"
            "local time is its UTC + local zone + 1 hr. DST\n"
            "       as utc: " << utc2 << "\n"
            "Using CET zone minutes:\n"
            "as local time: " << local2 << ", DST = " << local2.dst() << "\n"
            "      its utc: " << local2.utc() <<"\n\n";
}









