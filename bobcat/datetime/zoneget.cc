#include "datetime.ih"

// static
DateTime::Zone const &DateTime::Zone::get(std::string const &name)
{
    if (s_zone.empty())
        s_thisZoneShift = initialize();

    s_mutex.lock();

    auto iter = s_zone.find(name);

    if (iter == s_zone.end())
        throw Exception{ 1 } << "Unknown Zone `" << name << '\'';

    s_mutex.unlock();                   // iter.second holds the pointer,
                                        // which doesn't change if now
                                        // another zone is added

    return *(iter->second);    
}
