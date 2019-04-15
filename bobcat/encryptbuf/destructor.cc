#include "encryptbuf.ih"

EncryptBuf::~EncryptBuf()
{
    EVP_CIPHER_CTX_free(d_ctx);
}
