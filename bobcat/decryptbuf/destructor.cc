#include "decryptbuf.ih"

DecryptBuf::~DecryptBuf()
{
    if (not d_end)
        end();

    EVP_CIPHER_CTX_free(d_ctx);
}
