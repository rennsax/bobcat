#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    time_t utcSec = time(0);

    DateTime utcTime{ utcSec, DateTime::UTC };
    cout << utcTime << '\n';

    DateTime dateTime{ utcSec, DateTime::LOCALTIME };

    cout << dateTime << '\n';
}

