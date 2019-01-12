#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    {   
        DateTime utc{ 0, DateTime::UTC };
        DateTime local{
                        ::time(0),
                        DateTime::LOCALTIME };
    
        cout << "\nBeginning of the epoch:\n"
                "  utc time: " << utc << "\n"
                "local time: " << local << "\n"
                "   its utc: " << local.utc() <<"\n\n";
    }

    {   
        DateTime local{
                        ::time(0) + 6 * 31 * 24 * 3600,
                        DateTime::LOCALTIME };
    
        cout << "July after the beginning of the epoch:\n"
                "local time: " << local << "\n"
                "   its utc: " << local.utc() << "\n\n";
    }

}
