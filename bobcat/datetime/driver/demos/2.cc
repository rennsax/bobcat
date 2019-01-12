#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime local{ 120  };

    cout << 
            "zone shift +2 hours\n"
            "  utc time: " << local.utc() << "\n"
            "local time: " << local << '\n';
}
