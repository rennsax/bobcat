#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime2 utc;
    DateTime2 local{ DateTime2::LOCALTIME };

    cout << "local time:\n"
            "  utc time: " << utc << "\n"
            "local time: " << local << '\n';
}
