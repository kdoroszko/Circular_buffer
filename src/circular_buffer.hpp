#pragma once

#include <cstddef>
#include <deque>

template <typename T>
class Circular_buffer
{
public:
    Circular_buffer(std::size_t new_size) : size_(new_size) {}

private:
    std::deque<T> buffer_;
    std::size_t size_;
};