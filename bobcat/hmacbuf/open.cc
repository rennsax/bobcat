#include "hmacbuf.ih"

void HMacBuf::open()
{
    d_ctx = HMAC_CTX_new();

    HMAC_CTX_reset(d_ctx);
    HMAC_Init_ex(d_ctx, d_key.c_str(), d_key.length(), d_md, 0);

    setp(d_buffer, d_buffer + d_bufsize); 
}
