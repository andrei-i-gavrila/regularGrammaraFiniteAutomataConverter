//
// Created by agavrila on 2018-11-12.
//

#ifndef REFALFTC_STREAMOPS_H
#define REFALFTC_STREAMOPS_H

#include <ostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>


template<typename T> std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& set) {
    for (const auto& t: set) {
        os << t << ' ';
    }
    return os;
}

template<typename T, typename U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "{" << p.first << " => " << p.second << "}";
    return os;
}


template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    for (const auto& t: v) {
        os << t << ' ';
    }
    return os;
}


template <typename T, typename U> std::ostream& operator<<(std::ostream& os, const std::unordered_multimap<T, U>& mmap) {
    for (const auto& t: mmap) {
        os << t << ' ';
    }
    return os;
}

#endif //REFALFTC_STREAMOPS_H
