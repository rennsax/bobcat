inline DateTime::DateTime(std::istream  &&in, int zoneMinutes, 
                                                        DSTSpec const &spec)
:
    DateTime(in, zoneMinutes, spec)         // 19.cc
{}
