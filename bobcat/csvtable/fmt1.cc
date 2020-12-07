//#define XERR
#include "csvtable.ih"

void CSVTable::fmt(string const &fields)
{
    CSVTabDef tabDef{ d_format };
    tabDef.split(fields);
}
