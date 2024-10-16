// value_type *findPtr(Key const &key) const

template <typename Key, typename Value>
inline typename LinearMap<Key, Value>::iterator
        LinearMap<Key, Value>:: findPtr(Key const &key) const
{
    return std::find_if(begin(), end(),
        [&](value_type const &value)
        {
            return key == value.first; 
        }
    );
}
