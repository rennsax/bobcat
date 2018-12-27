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

    if (c == 0)             // newline without timestamp request
        d_empty = false;
    else
        checkTimestamp();

    switch (c)
    {
        case 0:             // write newline, without considering d_empty true
            c = '\n';       // also see logbuffer/operatorinsert.cc
        break;

        case 1:             // at fnl (forced new line) or ...
            c = '\n';
            d_active = true;
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
