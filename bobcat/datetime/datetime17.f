inline DateTime::DateTime(std::istream  &&in, int zoneMinutes)
:
    DateTime(in, zoneMinutes, DSTSpec{ false })         // 16.f
{}
