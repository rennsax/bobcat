#include "datetime.ih"

void DateTime::iniZoneDstPimpl()
{
    d_zone = d_type == UTC ? 0 : defaultZoneSecs();

    iniPimplTM(DSTSpec{ d_type == LOCALTIME } );
}
