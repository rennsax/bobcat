#include <iostream>
#include <iomanip>
#include <fstream>
#include <bobcat/exception>
#include "../encryptbuf"

#include <openssl/evp.h>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
        throw Exception(1) << 
                    "1st arg: method, 2nd arg: key, 3rd arg:  (opt): iv, "
                    "stdin: file to encrypt (to stdout)";

    // e.g., driver aes-128-cbc somekey < driver.cc > /tmp/drivr.enc

    string key(argv[2]);
    string iv;

    if (argc > 3)
        iv = argv[3];

    EncryptBuf encryptbuf(cout, argv[1], key, iv, 50);

    ostream out(&encryptbuf);
    cerr << "Block length: " << encryptbuf.blockLength() << "\n"
            "Key length: " << encryptbuf.keyLength() << "\n"
            "Max Key length: " << EVP_MAX_KEY_LENGTH << "\n"
            "actual IV length: " << encryptbuf.iv().length() << '\n';

//    cerr << hex << setfill('0');
//    for (unsigned char ch: encryptbuf.iv())
//        cerr << setw(2) << static_cast<unsigned>(ch);
//    cerr << '\n';

    out << cin.rdbuf() << end;
}
catch(exception const &err)
{
    cout << err.what() << endl;
    return 1;
}
