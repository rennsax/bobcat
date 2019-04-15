#include "digestbuf.ih"

void DigestBuf::close()
{
    char *digestbuf = new char[EVP_MAX_MD_SIZE];

    if (pptr() > pbase())
       EVP_DigestUpdate(d_ctx, d_buffer, pptr() - pbase());

    unsigned int digestbufLen;
         
    EVP_DigestFinal_ex(d_ctx, 
                    reinterpret_cast<unsigned char *>(digestbuf), 
                    &digestbufLen);
    d_digest.assign(digestbuf, digestbufLen);
    delete[] digestbuf;

    EVP_MD_CTX_free(d_ctx);
}
