#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime2 local{ DateTime2::LOCALTIME };

    cout << "local time: " << local << "\n"
            "rfc 2822: " << local.rfc2822() << "\n\n";
}
