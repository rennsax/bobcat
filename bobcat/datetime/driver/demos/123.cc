#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    string zone{ DateTime2::zoneTxt(DateTime2::defaultZoneMinutes()) };
    cout << "Info: local zone: " << zone << "\n\n";

    string date{ "Mon, 3 Dec 2018 13:29:11 +0100" };
    DateTime2 utc{ date };
    DateTime2 local{ date, DateTime2::LOCALTIME };
    cout << "Info: time = " << date << "\n"
            "       as utc: " << utc << "\n"
            "as local time: " << local << ", DST = " << local.dst() << "\n"
            "      its utc: " << local.utc() <<"\n\n";

    date = "Mon, 3 Jul 2018 13:29:11 +0100";
    DateTime2 utc2{ date };
    DateTime2 local2{ date, DateTime2::LOCALTIME };
    cout << "Info: time = " << date << "\n"
            "       as utc: " << utc2 << "\n"
            "as local time: " << local2 << ", DST = " << local2.dst() << "\n"
            "      its utc: " << local2.utc() <<"\n\n";
}
