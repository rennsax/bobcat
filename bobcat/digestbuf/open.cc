#include "digestbuf.ih"

void DigestBuf::open()
{
    d_ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(d_ctx, d_md, 0);
    setp(d_buffer, d_buffer + d_bufsize); 
}
