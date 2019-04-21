#include "decryptbuf.ih"

void DecryptBuf::setp()
{
    streambuf::setp(&*d_encrypted.begin(), &*d_encrypted.eoi());
}
