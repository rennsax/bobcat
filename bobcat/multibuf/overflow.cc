#include "multibuf.ih"

int MultiBuf::overflow(int c)
{
    if (c == EOF)
        pSync();
    else 
        d_buffer += c;

    return c;
}

