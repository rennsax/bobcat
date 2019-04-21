#include "digestbuf.ih"

int DigestBuf::overflow(int ch)
{
    EVP_DigestUpdate(d_ctx, ucharPtr(buffer()), bufSize());
    setp();

    if (ch != EOF)
    {
        *pptr() = ch;
        pbump(1);
    }
    return ch;
}
