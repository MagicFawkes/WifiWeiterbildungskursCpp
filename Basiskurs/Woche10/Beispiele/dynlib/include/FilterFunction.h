#pragma once

#include <vector>
#include <algorithm>
#include <iterator>

template<typename T, typename FilterFunc, typename TransformFunc>
std::vector<T> filter_and_transform(const std::vector<T>& input, FilterFunc filter, TransformFunc transform)
{
    std::vector<T> valuesFilteredAndTransformed;
    std::copy_if(input.begin(), input.end(), std::back_inserter(valuesFilteredAndTransformed), filter);
    std::transform(valuesFilteredAndTransformed.begin(), valuesFilteredAndTransformed.end(), valuesFilteredAndTransformed.begin(), transform);

    return valuesFilteredAndTransformed;
}
