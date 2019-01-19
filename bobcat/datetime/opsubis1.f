inline DateTime &DateTime::operator-=(int seconds)
{
    return *this += -seconds;
}

