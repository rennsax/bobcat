#include "hmacbuf.ih"

int HMacBuf::overflow(int ch)
{
    HMAC_Update(d_ctx, 
                reinterpret_cast<unsigned char *>(d_buffer), 
                d_bufsize);

    setp(d_buffer, d_buffer + d_bufsize);

    if (ch != EOF)
    {
        *pptr() = ch;
        pbump(1);
    }
    return ch;
}
