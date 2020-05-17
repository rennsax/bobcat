inline void Config::open(std::string const &fname)
{
    d_ptr->open(FBB::Exception::factory<std::ifstream>(fname));
}
