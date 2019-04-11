#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime2 local{ 120  };

    cout << 
        "using UTC of the local time, then using a zone shift of +2 hours\n"
        "  utc time: " << local.utc() << "\n"
        "local time: " << local << '\n';
}
