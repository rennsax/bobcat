#include "digestbuf.ih"

int DigestBuf::overflow(int ch)
{
    EVP_DigestUpdate(d_pimpl->ctx, d_pimpl->buffer, d_pimpl->bufsize);
    setp(d_pimpl->buffer, d_pimpl->buffer + d_pimpl->bufsize);

    if (ch != EOF)
    {
        *pptr() = ch;
        pbump(1);
    }
    return ch;
}
