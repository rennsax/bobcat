#include "log.ih"

void Log::init()
{
    d_activeLevel = ~0U;
    setLevel(0);
}
