#include "encryptbuf.ih"

int EncryptBuf::overflow(int ch)
{
    update();
    open();

    if (ch != EOF)
    {
        *pptr() = ch;         
        pbump(1);
    }
    return ch;
}
