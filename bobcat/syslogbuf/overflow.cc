#include "syslogbuf.ih"

int Syslogbuf::overflow(int ch)
{
    if (ch != EOF)
        buffer() += ch;
    else
        sync();

    return ch;
}
    
