#include <iostream>


extern "C" void app_main()
{
    auto counter = 0;
    while (true) {
        std::cout << "is this working" << std::endl;
        counter++;

        if (counter > 5) {
            abort();
        }
    }
}