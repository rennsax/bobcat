#include "digestbuf.ih"

DigestBuf::DigestBuf(char const *type, size_t bufsize)
:
    d_buffer(0),
    d_bufsize(bufsize)
{
    OpenSSL_add_all_digests();
    d_md = EVP_get_digestbyname(type);

    if (!d_md)
    {
        if (type == 0)
            type = "** unspecified digest type **";

        throw Exception{1} << "DigestBuf `" << type << "' not available";
    }
    d_buffer = new char[bufsize];
    open();
}
