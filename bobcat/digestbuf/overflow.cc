#include "digestbuf.ih"

int DigestBuf::overflow(int ch)
{
    EVP_DigestUpdate(d_ctx, d_buffer, d_bufsize);
    setp(d_buffer, d_buffer + d_bufsize);

    if (ch != EOF)
    {
        *pptr() = ch;
        pbump(1);
    }
    return ch;
}
