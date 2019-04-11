#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    {   
        DateTime2 utc{ 0, DateTime2::UTC };
        DateTime2 local{
                        ::time(0),
                        DateTime2::LOCALTIME };
    
        cout << "\nBeginning of the epoch:\n"
                "  utc time: " << utc << "\n"
                "local time: " << local << "\n"
                "   its utc: " << local.utc() <<"\n\n";
    }

    {   
        DateTime2 local{
                        (7 * 365 - 3) * 24 * 3600 + 6 * 31 * 24 * 3600,
                        DateTime2::LOCALTIME };
    
        cout << "July 7 years after the beginning of the epoch:\n"
                "local time: " << local << "\n"
                "   its utc: " << local.utc() << "\n\n";
    }

}

