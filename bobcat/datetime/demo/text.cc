#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime dt1{ "Mon Dec 3 13:29:11 2018", DateTime::LOCALTIME };

//    cout << "Localtime: " << dt1 << "\n"
//            "UTC: " << dt1.utc() << '\n';

    DateTime dt2{ "Mon Dec 3 13:29:11 CET 2018", DateTime::LOCALTIME };

//    cout << "Localtime: " << dt2 << "\n"
//            "UTC: " << dt2.utc() << '\n';

    DateTime dt3{ "Mon, 3 Dec 2018 13:29:11 +0100", DateTime::LOCALTIME };

    DateTime dt4{ "2018-12-03 13:29:11+01:00", DateTime::LOCALTIME };
}


