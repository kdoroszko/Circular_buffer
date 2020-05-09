#include "circular_buffer.hpp"

int main()
{
    Circular_buffer<int, 10> test_buffer;

    test_buffer.show_elements();
    test_buffer.push(1);
    test_buffer.push(2);
    test_buffer.push(3);
    test_buffer.show_elements();

    test_buffer.clear();
    test_buffer.show_elements();

    test_buffer.take_element();
    test_buffer.push(1);
    test_buffer.push(2);
    test_buffer.push(3);
    std::cout << "Take first element from buffer: " << test_buffer.take_element() << "\n\n";
    test_buffer.show_elements();

    std::cout << "Number of elements: " << test_buffer.size() << "\n\n";

    std::cout << "Maximum number of elements in bufffer: " << test_buffer.max_size() << "\n\n";

    return 0;
}
