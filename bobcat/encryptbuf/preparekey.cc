#include "encryptbuf.ih"

void EncryptBuf::prepareKey()
{
    d_key.resize(EVP_MAX_KEY_LENGTH);
}
