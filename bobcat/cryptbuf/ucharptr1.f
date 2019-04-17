// static
inline unsigned char *CryptBuf::ucharPtr(std::string &str)
{
    return reinterpret_cast<unsigned char *>(&str[0]);
}
