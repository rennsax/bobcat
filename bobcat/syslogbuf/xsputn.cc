#include "syslogbuf.ih"

// override

streamsize Syslogbuf::xsputn(char const *buf, streamsize nChars)
{
    buffer().append(buf, nChars);
    return nChars;
}
