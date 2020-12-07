template <Insertable Type>
inline CSVTabDef &operator<<(CSVTabDef &tab, Type const &value)
{
    return tab.insert(value);
}

template <Insertable Type>
inline CSVTabDef &operator<<(CSVTabDef &&tab, Type const &value)
{
    return tab << value;
}

