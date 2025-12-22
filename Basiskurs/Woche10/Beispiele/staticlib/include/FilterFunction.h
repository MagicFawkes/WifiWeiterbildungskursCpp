#pragma once
#include <vector>

template<typename T, typename FilterFunc, typename TransformFunc>
std::vector<T> filter_and_transform(
    const std::vector<T>& input,
    FilterFunc filter,
    TransformFunc transform
);