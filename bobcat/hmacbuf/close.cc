#include "hmacbuf.ih"

void HMacBuf::close()
{
    char *digestbuf = new char[EVP_MAX_MD_SIZE];

    if (pptr() > pbase())
       HMAC_Update(d_ctx, 
                   reinterpret_cast<unsigned char *>(d_buffer), 
                   pptr() - pbase());
         
    unsigned int digestbufLen;
    HMAC_Final(d_ctx, reinterpret_cast<unsigned char *>(digestbuf), 
               &digestbufLen);

    d_digest.assign(digestbuf, digestbufLen);
    HMAC_CTX_free(d_ctx);

    delete[] digestbuf;
}
