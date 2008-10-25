#include "argconfig.ih"

ArgConfig::const_RE_iterator 
                        ArgConfig::longConfigOpt(string const &longOpt) const
{
    string pattern = "^\\s*" + longOpt + "\\b";

    return beginRE(pattern);
}
