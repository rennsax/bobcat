#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    string zone{ DateTime::zoneTxt(DateTime::defaultZoneMinutes()) };
    cout << "Info: local zone: " << zone << "\n\n";

    string date{ "Mon, 3 Dec 2018 13:29:11 +0100" };
    DateTime utc{ date };
    DateTime local{ date, DateTime::LOCALTIME };
    cout << "Info: time = " << date << "\n"
            "       as utc: " << utc << "\n"
            "as local time: " << local << ", DST = " << local.dst() << "\n"
            "      its utc: " << local.utc() <<"\n\n";

    date = "Mon, 3 Jul 2018 13:29:11 +0100";
    DateTime utc2{ date };
    DateTime local2{ date, DateTime::LOCALTIME };
    cout << "Info: time = " << date << "\n"
            "       as utc: " << utc2 << "\n"
            "as local time: " << local2 << ", DST = " << local2.dst() << "\n"
            "      its utc: " << local2.utc() <<"\n\n";
}
