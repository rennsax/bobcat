#include "hmacbuf.ih"

int HMacBuf::overflow(int ch)
{
    HMAC_Update(d_pimpl->ctx, 
                reinterpret_cast<unsigned char *>(d_pimpl->buffer), 
                d_pimpl->bufsize);

    setp(d_pimpl->buffer, d_pimpl->buffer + d_pimpl->bufsize);

    if (ch != EOF)
    {
        *pptr() = ch;
        pbump(1);
    }
    return ch;
}
