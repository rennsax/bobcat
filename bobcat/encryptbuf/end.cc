#include "encryptbuf.ih"

void EncryptBuf::end_()         // overrides CryptBuf::end_()
{
    flushBuffer();

    int encryptedLen;
    if (not EVP_EncryptFinal_ex(d_ctx, ucharPtr(d_encrypted), &encryptedLen))
        throw Exception{ 1 } << "Encrypt finalization failed";

    d_outStream.write(&d_encrypted[0], encryptedLen);
}
