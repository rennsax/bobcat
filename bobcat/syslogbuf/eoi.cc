#include "syslogbuf.ih"

void Syslogbuf::eoi_()
{
    sync();   
    closelog();                     // syslog.h
}
