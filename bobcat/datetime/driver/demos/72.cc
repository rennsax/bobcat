#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    string zone{ DateTime::zone(DateTime::zone() / 60) };
    cout << "Info: local zone shift: " << zone << "\n"
            "      CET zone shift: " << 
                   DateTime::zone(DateTime::zoneShift("CET")) << "\n\n";

    string date{ "Mon Dec 3 13:29:11 CET 2018" };

    DateTime utc{ date };
    DateTime local{ date, DateTime::LOCALTIME };
    cout << "Info: time = " << date << "\n"
            "       as utc: " << utc << "\n"
            "Using CET zone shift:\n"
            "as local time: " << local << ", DST = " << local.dst() << "\n"
            "      its utc: " << local.utc() <<"\n\n";

    date = "Mon Jul 3 13:29:11 CET 2018";
    DateTime utc2{ date };
    DateTime local2{ date, DateTime::LOCALTIME };
    cout << "Info: time = " << date << "\n"
            "CET shifts 1 hour, so its UTC is at 12 hr. and its current\n"
            "local time is its UTC + local zone + 1 hr. DST\n"
            "       as utc: " << utc2 << "\n"
            "Using CET zone shift:\n"
            "as local time: " << local2 << ", DST = " << local2.dst() << "\n"
            "      its utc: " << local2.utc() <<"\n\n";
}









