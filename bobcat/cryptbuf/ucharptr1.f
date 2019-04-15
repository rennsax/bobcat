// static
inline unsigned char *EncryptBuf::ucharPtr(std::string &str)
{
    return reinterpret_cast<unsigned char *>(&str[0]);
}
