#include "decryptbuf.ih"

int DecryptBuf::overflow(int ch)
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
