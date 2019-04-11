#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;


int main()
try
{

    DateTime::Zone zone{"+1:00"};
    cout << "dst: " << zone.dstSeconds() << ", spec: "  << zone.spec() << '\n';

    zone = DateTime::Zone("CET");
    cout << "dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << '\n';

    zone = DateTime::Zone(":Asia/Calcutta");
    cout << "dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << '\n';

    zone = DateTime::Zone("+1:00", "+1:00");
    cout << "dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << '\n';

    zone = DateTime::Zone("+1:00", "+1:00", "Mar, last Sun", 
                                             "Oct, last Sun");
    cout << "dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << '\n';

    zone = DateTime::Zone("+1:00", "+1:00", "Mar, 1st Mon 2:00", 
                                             "Oct, 3rd Fri 3:00");
    cout << "dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << '\n';

    zone = DateTime::Zone::store("ZONE", "+1:00", "+1:00", 
                                    "Mar, last Sun", "Oct, last Sun");
    cout << "dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << '\n';

    zone = DateTime::Zone::store("ZONE", "+1:00", "-0:30", 
                                    "Mar, last Sun", "Oct, last Sun");
    cout << "dst (-1800): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << '\n';
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
}


