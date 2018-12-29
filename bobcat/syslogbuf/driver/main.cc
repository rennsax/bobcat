#include <ostream>
#include <iostream>

#include "../syslogbuf"

#include <bobcat/syslogstream>

using namespace std;
using namespace FBB;


int main(int argc, char **argv)
{
    cout << "messages are logged in /var/log/user.log\n";

    Syslogbuf sbuf(argv[0]);
    ostream sls(&sbuf);

    sls << "Hello world" << endl;
    sls << SyslogStream::notice << "Hello world" << endl;
}

