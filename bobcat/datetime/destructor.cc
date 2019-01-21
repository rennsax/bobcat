#include "datetime.ih"

DateTime::~DateTime()
{
    ZoneInfo::erase(this);
}
