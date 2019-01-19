template <typename Type>
inline DateTime &DateTime::operator-=(Type const &time)
{
    return *this += -std::chrono::seconds{ time }.count();
}

