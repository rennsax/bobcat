inline CF_Types::RE_iteratorPair CF_Pimpl::beginEndRE(std::string const &re)
{
    return beginEnd(re, &CF_Pimpl::findRE);
}
