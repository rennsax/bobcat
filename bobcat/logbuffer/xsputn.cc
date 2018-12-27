#include "logbuffer.ih"

streamsize LogBuffer::xsputn(char const *buffer, streamsize n) 
{
    if (d_active)
        checkTimestamp();

    streamsize begin = 0;
    while (true)
    {                                       // find the 1st newline pos.
        streamsize end = newLine(buffer, begin, n);    

        if (d_active)                       // insert the prefix
            d_stream->write(buffer + begin, end - begin);

        if (end == n)                       // at end of buffer
            break;                          // then done

        overflow(buffer[end]);              // handle time stamps etc.
        begin = end + 1;                    // go beyond the nl separator
    }

    return n;
}
