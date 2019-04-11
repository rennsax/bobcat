#include "datetime.ih"

void DateTime::setZone(Zone const &zone)
{
    d_type = LOCALTIME;

    Pimpl::set(this, zone);
    assignTM();    
}
