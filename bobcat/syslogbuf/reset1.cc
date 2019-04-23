#include "syslogbuf.ih"

void Syslogbuf::reset(std::string const &ident, 
                     Priority priority, Facility facility, int option)
{
    eoi();
    d_orgPriority = d_priority = priority;

    reset(ident, facility, option);
}
