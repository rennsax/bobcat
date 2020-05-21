inline void Config::load(std::string const &fname)
{
    d_ptr->load(FBB::Exception::factory<std::ifstream>(fname));
}
