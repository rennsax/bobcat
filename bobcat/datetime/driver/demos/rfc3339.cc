#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime local{ DateTime::LOCALTIME };

    cout << "local time: " << local << "\n"
            "rfc 3339: " << local.rfc3339() << "\n\n";
}
