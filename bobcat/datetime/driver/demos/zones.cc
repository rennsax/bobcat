#include <iostream>

#include "../../datetime"

using namespace std;
using namespace FBB;

int main()
try
{
    DateTime::readZones("zones");
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
}
