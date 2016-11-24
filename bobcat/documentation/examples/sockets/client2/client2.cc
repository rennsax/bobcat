#include <iostream>
#include <exception>

#include <bobcat/clientsocket>
#include <bobcat/ofdstream>
#include <bobcat/ifdstream>
#include <bobcat/a2x>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc != 3)
    {
        cerr << "Provide servername and port number\n";
        return 1;
    }

    size_t     port = A2x(argv[2]);
    ClientSocket client(argv[1], port);
    int fd = client.connect();
    string line;

    cout << "Connecting to socket " << fd << endl <<
            "address = " << client.dottedDecimalAddress() << ", " <<
                                                             endl <<
            "communication through port " << client.port() << endl;

    IFdStream in(fd);                 // stream to read from
    OFdStream out(fd);                // stream to write to

    while (true)
    {
                                // Ask for a textline, stop if
        cout << "? ";           // empty / none
        if (!getline(cin, line) || line.length() == 0)
            return 0;
        cout << "Line read: " << line << endl;

                                // Return the line to the server
        out << line.c_str() << endl;
        cout << "wrote line\n";

        getline(in, line);      // Wait for a reply from the server
        cout << "Answer: " << line << endl;
    }
}
catch (exception const &err)
{
    cerr << err.what() << "\n" <<
            "Can't connect to " << argv[1] << ", port " <<
            argv[2] << '\n';
    return 1;
}
