template <typename Type>
DateTime &DateTime::operator+=(Type const &time)
{
    DateTime tmp{ *this };
    tmp.d_time += std::chrono::seconds{ time }.count();

    return install(tmp);
}

