#include "gtest/gtest.h"
#include "circular_buffer.hpp"

TEST(Clear, ClearBuffer)
{
    Circular_buffer<int, 3> empty_buffer;
    empty_buffer.clear();

    Circular_buffer<int, 3> test_buffer;
    test_buffer.push(1);
    test_buffer.clear();

    ASSERT_EQ(empty_buffer.size(), 0);
    ASSERT_EQ(test_buffer.size(), 0);
}

TEST(Push, FillBuffer)
{
    Circular_buffer<int, 3> test_buffer;

    test_buffer.push(1);
    ASSERT_EQ(test_buffer.size(), 1);

    test_buffer.push(2);
    ASSERT_EQ(test_buffer.size(), 2);

    test_buffer.push(3);
    ASSERT_EQ(test_buffer.size(), 3);

    test_buffer.take_element();
    test_buffer.push(4);
    ASSERT_EQ(test_buffer.size(), 3);
}

TEST(Push, OverfillBuffer)
{
    Circular_buffer<int, 3> test_buffer;

    test_buffer.push(1);
    test_buffer.push(2);
    test_buffer.push(3);
    test_buffer.push(4);

    ASSERT_EQ(test_buffer.size(), 3);
}

TEST(TakeElement, TakeElementFromFrontPosition)
{
    Circular_buffer<int, 3> test_buffer;
    test_buffer.push(1);

    ASSERT_EQ(test_buffer.take_element(), 1);
}

TEST(TakeElement, TakeElementFromBackPosition)
{
    Circular_buffer<int, 3> test_buffer;
    test_buffer.push(1);
    test_buffer.push(2);
    test_buffer.clear();
    test_buffer.push(3);

    ASSERT_EQ(test_buffer.take_element(), 3);
}

TEST(TakeElement, TakeFewElements)
{
    Circular_buffer<int, 3> test_buffer;
    test_buffer.push(1);
    test_buffer.push(2);
    test_buffer.push(3);

    ASSERT_EQ(test_buffer.take_element(), 1);
    ASSERT_EQ(test_buffer.take_element(), 2);
    ASSERT_EQ(test_buffer.take_element(), 3);
}

TEST(Size, BufferIsEmpty)
{
    Circular_buffer<int, 3> test_buffer;

    ASSERT_EQ(test_buffer.size(), 0);
}

TEST(Size, BufferIsFull)
{
    Circular_buffer<int, 3> test_buffer;
    test_buffer.push(1);
    test_buffer.push(2);
    test_buffer.push(3);

    ASSERT_EQ(test_buffer.size(), 3);
}

TEST(Size, ReadPositionLessThanWritePosition)
{
    Circular_buffer<int, 3> test_buffer;
    test_buffer.push(1);

    ASSERT_EQ(test_buffer.size(), 1);
}

TEST(Size, WritePositionLessThanReadPosition)
{
    Circular_buffer<int, 3> test_buffer;
    test_buffer.push(1);
    test_buffer.push(2);
    test_buffer.push(3);
    test_buffer.take_element();
    test_buffer.take_element();
    test_buffer.push(4);

    ASSERT_EQ(test_buffer.size(), 2);
}

TEST(MaxSize, MaxSizeOfBuffer)
{
    Circular_buffer<int, 3> test_buffer3;
    Circular_buffer<int, 10> test_buffer10;
    Circular_buffer<int, 100> test_buffer100;

    ASSERT_EQ(test_buffer3.max_size(), 3);
    ASSERT_EQ(test_buffer10.max_size(), 10);
    ASSERT_EQ(test_buffer100.max_size(), 100);
}
