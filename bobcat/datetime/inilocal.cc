#include "datetime.ih"

void DateTime::iniLocal(DSTSpec const &spec)
{
    d_type = LOCALTIME;
    iniDSTInfoTM(spec);
}
