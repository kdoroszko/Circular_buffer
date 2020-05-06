#include "circular_buffer.hpp"

int main()
{
    Circular_buffer<int> test_buffer(10);

    test_buffer.show_elements();
    test_buffer.push(1);
    test_buffer.push(2);
    test_buffer.push(3);
    test_buffer.show_elements();

    return 0;
}