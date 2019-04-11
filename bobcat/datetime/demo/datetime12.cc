#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
  cout << "format type 1:\n";
  {

    DateTime utc{ "Mon Jul 3 13:00:00 2018", DateTime::UTC };
    cout << utc << '\n';

    // Note: these time specifications do not honor DST

    DateTime local{ "Mon Jul 3 13:00:00 2018", DateTime::LOCALTIME };
    cout << local << ", as UTC:\n" <<
            local.utc() << '\n';
  }

  cout << "format type 2:\n";
  {

    DateTime utc{ "Mon Jul 3 13:00:00 CET 2018", DateTime::UTC };
    cout << utc << '\n';

    // Note: these time specifications do not honor DST

    DateTime local{ "Mon Jul 3 13:00:00 CET 2018", DateTime::LOCALTIME };
    cout << local << ", as UTC:\n" <<
            local.utc() << '\n';
  }

  cout << "format type 3:\n";
  {

    DateTime utc{ "Mon, 3 Jul 2018 13:00:00 +0100", DateTime::UTC };
    cout << utc << '\n';

    // Note: these time specifications do not honor DST

    DateTime local{ "Mon, 3 Jul 2018 13:00:00 +0100", DateTime::LOCALTIME };
    cout << local << ", as UTC:\n" <<
            local.utc() << '\n';
  }

  cout << "\n"
          "format type 4:\n";
  {
    DateTime utc{ "2018-12-03 13:00:00+01:00", DateTime::UTC };
    cout << utc << '\n';

    DateTime local{ "2018-12-03 13:00:00+01:00", DateTime::LOCALTIME };
    cout << local << ", as UTC:\n" <<
            local.utc() << '\n';
  }
}



