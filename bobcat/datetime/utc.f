inline DateTime DateTime::utc() const
{
    return DateTime{ d_time, UTC };
}   
