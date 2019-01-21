#include "datetime.ih"

void DateTime::iniZoneDstZoneInfo()
{
    d_zone = d_type == UTC ? 0 : defaultZoneSecs();

    iniZoneInfoTM(DSTSpec{ d_type == LOCALTIME } );
}
