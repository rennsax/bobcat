inline DateTime::TimeFields constexpr operator|(
            DateTime::TimeFields lhs, DateTime::TimeFields rhs)
{
    return static_cast<DateTime::TimeFields>(
                static_cast<uint16_t>(lhs) | static_cast<uint16_t>(rhs) 
            );
}
