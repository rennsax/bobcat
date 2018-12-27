#include "ofdstreambuf.ih"

int OFdStreambuf::overflow(int ch)
{
    sync();                                     
    if (ch != EOF)
    {
        *pptr() = ch;
        pbump(1);
    }
    return ch;
}
    
