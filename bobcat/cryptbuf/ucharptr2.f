// static
inline unsigned char const *EncryptBuf::ucharPtr(std::string const &str)
{
    return reinterpret_cast<unsigned char const *>(&str[0]);
}
