#include "decryptbuf.ih"

DecryptBuf::~DecryptBuf()
{
    EVP_CIPHER_CTX_free(d_ctx);
}
