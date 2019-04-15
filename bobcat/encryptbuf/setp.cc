#include "encryptbuf.ih"

void EncryptBuf::setp()
{
    streambuf::setp(&*d_incoming.begin(), &*d_incoming.end());
}

