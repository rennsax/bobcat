#include "syslogbuf.ih"

int Syslogbuf::overflow(int ch)
{
    if (ch != EOF)
        d_data->buffer += ch;
    else
        sync();

    return ch;
}
    
