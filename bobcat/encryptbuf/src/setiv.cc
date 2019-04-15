//#include "encryptbuf.ih"
//
//void EncryptBuf::setIv(string iv)
//{
//    if (d_active)
//        throw Exception{1} << "Can't change IV during encryption";
//
//    d_iv = iv;
//
//    iv.resize(EVP_MAX_IV_LENGTH);
//    if 
//    (
//        not EVP_EncryptInit_ex(d_ctx, 0, 0, 0,
//            reinterpret_cast<unsigned char const *>(iv.data()))
//    )
//        throw Exception{1} << "Couldn't set IV";
//}
//
