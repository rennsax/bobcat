#include "decryptbuf.ih"

DecryptBuf::DecryptBuf(ostream &outStream, char const *type, 
                        string const &key, string const &iv, size_t bufSize)
:
    d_ctx(EVP_CIPHER_CTX_new()),
    d_encrypted(bufSize < EVP_MAX_BLOCK_LENGTH ? 
                    (bufSize = EVP_MAX_BLOCK_LENGTH) 
                : 
                    bufSize, 
                0),
    d_decrypted(bufSize, 0),
    d_iv(iv),
    d_key(key),
    d_outStream(outStream)
{
    setMD(type);

    if (
        not EVP_DecryptInit_ex(d_ctx, d_md, 0,
                               ucharPtr(&d_key[0]), ucharPtr(&d_iv[0]))
    )
        throw Exception{ 1 } << "DecryptBuf: initialization failed";

////    d_cipherBlockSize = EVP_CIPHER_CTX_block_size(d_ctx);

    setp();
}







