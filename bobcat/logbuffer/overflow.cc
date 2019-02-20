#include "logbuffer.ih"

int LogBuffer::overflow(int c)
{
    if (c != 1 and not d_active)    // ignore the char if we're not active.
    {                               // and if the ch. is not fnl (forced \n)
        if (c == '\n')
        {
            d_empty = true;
            d_active = true;
        }
        return c;
    }

    switch (c)
    {
        case 0:             // write newline, without considering d_empty true
            d_empty = false;
            c = '\n';       // also see logbuffer/operatorinsert.cc
        break;

        case 1:             // at fnl (forced new line) (re)activate and
            c = '\n';       // fallthrough (continue) as \n
        [[fallthrough]];

        case '\n':          // at '\n', set d_empty to true. This generates 
                            // a timestamp at the next insertion
            d_empty = true;
        break;
    }

    return 
        d_stream->write(reinterpret_cast<char const *>(&c), sizeof(char)) ?
            c
        :
            EOF;
}
