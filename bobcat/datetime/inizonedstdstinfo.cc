#include "datetime.ih"

void DateTime::iniZoneDstDSTInfo()
{
    d_zone = d_type == UTC ? 0 : defaultZoneSecs();

    iniDSTInfoTM(DSTSpec{ d_type == LOCALTIME } );
}
