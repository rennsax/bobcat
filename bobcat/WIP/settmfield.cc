#include "datetime.ih"

bool DateTime::setTMfield(int TM::*field, int value)
try
{
    DateTime tmp{ *this };
    tmp.d_tm.*field = value;

    tmp.updateTM();
    swap(tmp);

    return true;
}
catch (...)
{
    return false;
}

