#include "LookupTable.h"

LookupTable::LookupTable(const std::vector<double>& x, const std::vector<double>& y)
    : x{ x },
      y{ y }
{

}

double LookupTable::get(const double t)
{
    int sz = x.size();
    if (sz == 0 || y.size() != sz)
        throw std::invalid_argument("Vectors must be non-empty and have equal size.");

    for (int i = 0; i < sz; i++)
    {
        if (t <= x[i])
        {
            if (i > 0)
            {
                double denom = (x[i] - x[i - 1]);
                return ((y[i] - y[i - 1]) / denom * t +
                    (x[i] * y[i - 1] - x[i - 1] * y[i]) / denom);
            }
            return y[0];
        }
    }
    return y[sz - 1];
}

