#ifndef UTIL_H
#define UTIL_H

#include <vector>

namespace Util {

    template<class T>
    bool contains(const std::vector<T> &vector, const T &targetValue) {
        return find(vector.begin(), vector.end(), targetValue) != vector.end();
    }

    template<class T, typename lambda>
    int getPositionIf(const std::vector<T> &vector, lambda predicate) {
        auto iterator = find_if(vector.begin(), vector.end(), predicate);
        if (iterator != vector.end())
            return distance(vector.begin(), iterator);
        return -1;
    }

    template<class T, typename lambda>
    T getMaxOf(const std::vector<T> &vector, lambda predicate) {
        return *max_element(vector.begin(), vector.end(), predicate);
    }

    template<class T, typename lambda>
    T getMinOf(const std::vector<T> &vector, lambda predicate) {
        return *min_element(vector.begin(), vector.end(), predicate);
    }

    template<class T>
    int getPosition(const std::vector<T> &vector, const T &targetValue) {
        auto iterator = find(vector.begin(), vector.end(), targetValue);
        if (iterator != vector.end())
            return distance(vector.begin(), iterator);
        return -1;
    }

    template<class T>
    T popFrom(std::stack<T> &targetStack) {
        T target = targetStack.top();
        targetStack.pop();
        return target;
    }
}

#endif
