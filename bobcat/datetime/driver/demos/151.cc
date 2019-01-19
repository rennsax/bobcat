#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    string zone{ DateTime::zoneTxt(DateTime::defaultZoneMinutes()) };
    cout << "Info: local zone: " << zone << "\n"
            "      CET zone: " << 
                   DateTime::zoneTxt(DateTime::minutes("CET")) << "\n\n";

    string date{ "Mon Dec 3 13:29:11 2018" };

    DateTime local{ date, 120 };
    cout << "Info: input time: " << date << " (UTC)\n"
            "as local time (UTC +2 hr): " << local << ", DST = " << 
                                                        local.dst() << "\n"
            "      its utc (-2 hr.): " << local.utc() <<"\n\n";

    date = "Mon Jul 3 13:29:11 2018";

    DateTime local2{ date, 120 };

    cout << "Info: input time = " << date << " (UTC)\n"
            "as local time (also 15:29.11): " << local2 << ", DST = " << 
                                                        local2.dst() << "\n"
            "      its utc (-2 hr.): " << local2.utc() <<"\n\n";

    DateTime local3{ date, 120,
                DateTime::DSTSpec{ true } };

    cout << "Info: input time = " << date << " (UTC), using DST (-> 18.cc)\n"
            "as local time (16:29.11): " << local3 << ", DST = " << 
                                                        local3.dst() << "\n"
            "      its utc (-3 hr.): " << local3.utc() <<"\n\n";
}









