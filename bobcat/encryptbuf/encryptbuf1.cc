#include "encryptbuf.ih"

EncryptBuf::EncryptBuf(ostream &outStream, char const *type, 
                       string key, string const &iv, size_t bufSize)
:
    CryptBuf(type),
    d_ctx(EVP_CIPHER_CTX_new()),
    d_incoming(bufSize, 0),
    d_encrypted(bufSize + EVP_MAX_BLOCK_LENGTH, 0),
    d_iv(iv),
    d_key(key),
    d_outStream(outStream)
{
    prepareIV();
    prepareKey();

    d_key = key;

    if (
        not EVP_EncryptInit_ex(d_ctx, md(), 0, ucharPtr(d_key), 
                                               ucharPtr(d_iv))
    )
        throw Exception{ 1 } << "Encrypt initialization failed";


//    cerr << "key len: " << d_key.length() << ": `" << d_key << "'\n"
//            "iv len: " << d_iv.length() << ": `" << d_iv << "'\n"
//            "incoming: `";
    
    setp();  
}





