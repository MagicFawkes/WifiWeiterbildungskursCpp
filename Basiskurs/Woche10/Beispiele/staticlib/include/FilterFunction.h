#pragma once
#include <vector>
#include <functional>

template<typename T, typename FilterFunc, typename TransformFunc>
std::vector<T> filter_and_transform(
    const std::vector<T>& input,
    FilterFunc filter,
    TransformFunc transform
);

// 🔴 WICHTIG: Ankündigung der Instanz
extern template std::vector<int>
filter_and_transform<int, std::function<bool(int)>, std::function<int(int)>>(
    const std::vector<int>&,
    std::function<bool(int)>,
    std::function<int(int)>
);