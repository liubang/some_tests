//=====================================================================
//
// array.h -
//
// Created by liubang on 2023/10/19 22:25
// Last Modified: 2023/10/19 22:25
//
//=====================================================================

#pragma once

#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <string>

namespace pl {

template <typename T, size_t N> class Array {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using iterator = T*;
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<T*>;
    using const_reverse_iterator = std::reverse_iterator<const T*>;

public:
    T& operator[](size_t i) noexcept { return elements_[i]; }
    const T& operator[](size_t i) const noexcept { return elements_[i]; }

    T& at(size_t i) {
        if (i >= N) [[__unlikely__]] {
            throw std::runtime_error("out of range at index " + std::to_string(i) + ", size " +
                                     std::to_string(N));
        }
        return elements_[i];
    }

    const T& at(size_t i) const {
        if (i >= N) [[__unlikely__]] {
            throw std::runtime_error("out of range at index " + std::to_string(i) + ", size " +
                                     std::to_string(N));
        }
        return elements_[i];
    }

    T& front() noexcept { return elements_[0]; }
    const T& front() const noexcept { return elements_[0]; }

    T& back() noexcept { return elements_[N - 1]; }
    const T& back() const noexcept { return elements_[N - 1]; }

    static constexpr bool empty() noexcept { return N == 0; }
    static constexpr size_t size() noexcept { return N; }

    T* data() noexcept { return elements_; }
    const T* data() const noexcept { return elements_; }

    std::reverse_iterator<T const*> rbegin() const noexcept {
        return std::make_reverse_iterator(elements_);
    }

    std::reverse_iterator<T const*> rend() const noexcept {
        return std::make_reverse_iterator(elements_ + N);
    }

    std::reverse_iterator<T*> rbegin() noexcept { return std::make_reverse_iterator(elements_); }

    std::reverse_iterator<T*> rend() noexcept { return std::make_reverse_iterator(elements_ + N); }

private:
    T elements_[N];
};

} // namespace pl
