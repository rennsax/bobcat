//#define XERR
#include "configfile.ih"

ConfigFile::RE_iteratorPair CF_Pimpl::beginEndRE(
                                            std::string const &re)
{
    d_CIvect.clear();

    auto beyond = end();
    auto from = begin();

    while (true)
    {
        from = findRE(re, from);

        if (from == beyond)
            break;

        d_CIvect.push_back(from);
        ++from;
    }

    return RE_iteratorPair{ d_CIvect.cbegin(), d_CIvect.cend() };
}
