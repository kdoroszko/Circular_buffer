#pragma once

#include <cstddef>
#include <deque>
#include <iostream>

template <typename T>
class Circular_buffer
{
public:
    Circular_buffer(std::size_t new_size) : size_(new_size) {}

    void clear() {buffer_.clear();}

    void push(const T new_element)
    {
        if(buffer_.size() < size_)
            buffer_.emplace_back(new_element);
        else std::cout << "Buffer is full! Can't add any new object!\n";
    }

    void show_elements() const
    {
        std::cout << "--- Elements in buffer ---\n";

        if(buffer_.empty())
            std::cout << "\tBuffer is empty!\n\n";
        else
        {
            for(const auto &elem: buffer_)
                std::cout << elem << '\n';
            std::cout << '\n';
        }
    }

private:
    std::deque<T> buffer_;
    std::size_t size_;
};