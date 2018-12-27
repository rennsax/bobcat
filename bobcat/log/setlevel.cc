#include "log.ih"

void Log::setLevel(size_t newLevel)
{
    d_level = newLevel;
    d_activeLevel = ~0U;
    level(d_activeLevel);
}
