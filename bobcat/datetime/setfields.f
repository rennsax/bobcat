inline bool DateTime::setFields(TM const &ts, int fields)
{
    return setFields(ts, static_cast<TimeFields>(fields));
}
