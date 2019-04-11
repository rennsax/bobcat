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

    string date{ "Mon Dec 3 13:29:11 2018" };

    DateTime2 utc{ date };
    DateTime2 local{ date, DateTime2::LOCALTIME };

    cout << "Info: input time = " << date << " (no zone specification)\n"
            "       now as utc (same): " << utc << "\n"
            "now as local time (same): " << local << ", DST = " << 
                                                        local.dst() << "\n"
            "      its utc (-1 hr.): " << local.utc() <<"\n\n";

    date = "Mon Jul 3 13:29:11 2018";
    DateTime2 utc2{ date };
    DateTime2 local2{ date, DateTime2::LOCALTIME };

    cout << "Info: input time = " << date << " (no zone specification)\n"
            "       as utc (same): " << utc2 << "\n"
            "as local time (same): " << local2 << ", DST = " << 
                                                        local2.dst() << "\n"
            "      its utc (-2 hr.): " << local2.utc() <<"\n\n";
}









