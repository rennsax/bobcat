inline DateTime DateTime::timeZone(int displayZone) const
{
    return DateTime(d_time, displayZone);
}
