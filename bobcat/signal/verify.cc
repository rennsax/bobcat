#include "signal.ih"

// This is required for the hurd-i386 arch, which apparently 
// fails to implement the POSIX standard:

#ifndef SIGRTMAX
// Darwin doesn't define SIGRTMAX.
#ifndef _NSIG
#define _NSIG 32
#endif
    #define SIGRTMAX _NSIG
#endif        

void Signal::verify(size_t signum, char const *member)
{
    if (signum > static_cast<size_t>(SIGRTMAX))
        throw Exception{1} <<  member << " signal " << signum << " exceeds "
                        "max. signum (" << SIGRTMAX << ')';
}
