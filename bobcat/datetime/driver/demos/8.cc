#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    cout << "\nALL zones are shifted 2 hours wrt UTC\n\n";
    {
        DateTime local{ 0, 120, DateTime::DSTSpec{ false }  };
        cout << "Beginning of the epoch (+ 2 hrs zone shift):\n"
                "local time: " << local << "\n"
                "   its utc: " << local.utc() <<"\n\n";
    }

    {
        DateTime local{ 
            time(0),    // use local UTC as UTC
            120,        // current local time +2 hours ahead
            DateTime::DSTSpec{ "0101", "0301", -60 } 
        };
        cout << "Today  (+2 hrs zone shift):\n"
            "local time: " << local << ", local DST: " << local.dst() << "\n"
            "   its utc: " << local.utc() <<"\n\n";
    }

    {
                                            // std DST, local DST interval
        DateTime local{ ::time(0), 120, DateTime::DSTSpec{ true }  }; 
        cout << "Current time (utc + 2 hrs zone shift):\n"
                "local time: " << local << ", dst = " << local.dst() << "\n"
                "   its utc: " << local.utc() <<"\n\n";
    }

    {
        DateTime local{ ::time(0) + 6 * 31 * 24 * 3600, 120,
              DateTime::DSTSpec{ true }  }; 
        cout << "\ncurrent time + 2 hrs zone shift + 1/2 year\n" 
                "Current time (utc + 6 months + 2 hrs zone shift + DST):\n"
                "local time: " << local << ", dst = " << local.dst() << "\n"
                "   its utc: " << local.utc() <<"\n\n";
    }
}


