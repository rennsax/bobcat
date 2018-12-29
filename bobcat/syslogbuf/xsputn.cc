#include "syslogbuf.ih"

// override

streamsize Syslogbuf::xsputn(char const *buffer, streamsize nChars)
{
    d_data->buffer.append(buffer, nChars);
    return nChars;
}
