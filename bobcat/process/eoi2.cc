#include "process.ih"

void Process::eoi_()
{
    if (active())
    {
        close();
        d_data->d_exitStatus = waitForChild();
    }
}

