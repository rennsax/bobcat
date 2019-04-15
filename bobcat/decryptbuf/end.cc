#include "decryptbuf.ih"

void DecryptBuf::end()
{
    flushBuffer();

    int restLen;
    if (
        not EVP_DecryptFinal_ex(d_ctx, 
                                ucharPtr(&d_decrypted[0]), 
                                &restLen)
    )
        throw Exception{ 1 } << "DecryptBuf: padding error";

    d_outStream.write(&d_decrypted[0], restLen);
}











