#include "encryptbuf.ih"

EncryptBuf::~EncryptBuf()
{
    if (not d_end)
        end();

    EVP_CIPHER_CTX_free(d_ctx);
}
