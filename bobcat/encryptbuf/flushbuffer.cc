#include "encryptbuf.ih"


void EncryptBuf::flushBuffer()  // called by overflow when d_buffer is 
                                // full and by end()
{
    int incomingLen = pptr() - pbase();

    int encryptedLen;
    if (
        not EVP_EncryptUpdate(d_ctx, 
                              ucharPtr(d_encrypted), &encryptedLen, 
                              ucharPtr(d_incoming),  incomingLen)
    )
        throw Exception{ 1 } << "Encrypt update failed";

    d_outStream.write(&d_encrypted[0], encryptedLen);

    setp();                     // reset the buffer
}
