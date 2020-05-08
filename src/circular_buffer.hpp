#pragma once

#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
class Circular_buffer
{
public:
    Circular_buffer() : write_position_(0), read_position_(0),
                        last_operation_was_read_(true) {}

    void clear()
    {
        read_position_ = write_position_;
        last_operation_was_read_ = true;
    }

    void push(const T new_element)
    {
        if(is_full())
            std::cout << "Buffer is full! Can't add any new object!\n\n";
        else
        {
            buffer_.at(write_position_++) = new_element;
            last_operation_was_read_ = false;

            if(write_position_ == N)
                write_position_ = 0;
        }
    }

    void show_elements() const
    {
        std::cout << "--- Elements in buffer ---\n";

        if(is_empty())
            std::cout << "\tBuffer is empty!\n\n";
        else if(is_full())
        {
            for(const auto &elem: buffer_)
                std::cout << elem << '\n';
                std::cout << '\n';
        }
        else
        {
            for(std::size_t i = read_position_; i < write_position_; ++i)
                std::cout << buffer_.at(i) << '\n';
            std::cout << '\n';
        }
    }

private:
    bool is_empty() const
    {
        return write_position_ == read_position_
                && last_operation_was_read_ == true;
    }

    bool is_full() const
    {
        return write_position_ == read_position_
                && last_operation_was_read_ == false;
    }

    std::array<T, N> buffer_;
    std::size_t write_position_;
    std::size_t read_position_;
    bool last_operation_was_read_;
};
