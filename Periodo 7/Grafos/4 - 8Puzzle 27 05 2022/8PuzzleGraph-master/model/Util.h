#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <queue>
#include <stack>

namespace Util {

    template<class T>
    bool contains(const std::vector<T> &vector, const T &targetValue) {
        return find(vector.begin(), vector.end(), targetValue) != vector.end();
    }

    template<class T>
    int getPosition(const std::vector<T> &vector, const T &targetValue) {
        auto iterator = find(vector.begin(), vector.end(), targetValue);
        if (iterator != vector.end())
            return distance(vector.begin(), iterator);
        return -1;
    }

}

#endif
