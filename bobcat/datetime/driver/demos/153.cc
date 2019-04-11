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

    string date{ "Mon, 3 Dec 2018 13:29:11 +0100" };
    DateTime2 local{ date, 120 };
    cout << "Info: input time " << date << "\n"
            "as local time (UTC +2 hr.): " << local << 
                                            ", DST = " << local.dst() << "\n"
            "      its utc (-2 hr.): " << local.utc() <<"\n\n";

    date = "Mon, 3 Jul 2018 13:29:11 +0100";
    DateTime2 local2{ date, 120 };
     cout << "Info: input time = " << date << "\n"
            "as local time (also 14:29:11, as DST is suppressed):\n" << 
            "     " << local2 << ", DST = " << local2.dst() << "\n"
            "      its utc (-2 hr.): " << local2.utc() <<"\n\n";
}









