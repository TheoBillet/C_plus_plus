// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template<class T>
void swap(T& x, T& y)
{
    int temp = x;
    x = y;
    y = temp;
}

template<class T>
void my_selection_sort(T begin, T end)
{
    T i, j, min_idx, min_idx2;
    for (i = begin; i != end; ++i)
    {
        min_idx = i;
        min_idx2 = i;
        for (j = ++min_idx2; j != end; ++j)
            if (*j < *min_idx)
                min_idx = j;

        if (min_idx != i)
            swap(*min_idx, *i);
    }
}