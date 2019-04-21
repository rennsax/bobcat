#include "hmacbuf.ih"

// override
void HMacBuf::eoi_()
{
    char *digestbuf = new char[EVP_MAX_MD_SIZE];

    if (pptr() > pbase())
       HMAC_Update(d_ctx, ucharPtr(buffer()), pptr() - pbase());
         
    unsigned digestbufLen;
    HMAC_Final(d_ctx, reinterpret_cast<unsigned char *>(digestbuf), 
               &digestbufLen);

    d_digest.assign(digestbuf, digestbufLen);
    HMAC_CTX_free(d_ctx);
    d_ctx = 0;

    delete[] digestbuf;
}
