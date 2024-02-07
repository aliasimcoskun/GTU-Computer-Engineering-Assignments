#include "PFArray.h"
#include "PFArray.cpp"

int main()
{
    // Test empty function 
    std::cout << "\nTest empty() function: " << std::endl;
    PFArray<int> first;
    if (first.empty()) {
        std::cout << "first is empty" << std::endl;
    }
    else {
        std::cout << "first is not empty" << std::endl;
    }

    // Test size function
    std::cout << "\nTest size() function: " << std::endl;
    PFArray<int> second(5, 2); //create an array with a size of 5 and fill it with 2
    std::cout << "second has size " << second.size() << std::endl;

    // Test erase function
    std::cout << "\nTest erase() function: " << std::endl;
    second.erase(second.begin());
    std::cout << "second has size " << second.size() << std::endl;

    // Test clear function
    std::cout << "\nTest clear() function: " << std::endl;
    second.clear();
    std::cout << "second has size " << second.size() << std::endl;
    
    // Test begin and end functions
    PFArray<int> third(5, 3); //create an array with a size of 5 and fill it with 3
    std::cout << "\nTest begin() and end() function: " << std::endl;
    for (PFArray<int>::IterInner it = third.begin(); it != third.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Test cbegin and cend functions
    std::cout << "\nTest cbegin() and cend() function: " << std::endl;
    for (PFArray<int>::IterInner it = third.cbegin(); it != third.cend(); ++it) {
        std::cout << *it << std::endl;
    }

    // Test range based for loop
    std::cout << "\nTest range based for loop: " << std::endl;
    for (auto x : third) {
        std::cout << x << std::endl;
    }

    // Test std::find function
    std::cout << "\nTest std::find() function: " << std::endl;
    std::cout << "We create an array with a size of 6 and fill it with 1." << std::endl;
    PFArray<int> fourth(6, 1);
    std::cout << "and we replace the element whose index is 3 with 4(using operator[] overload)." << std::endl;
    fourth[3] = 4;
    std::cout << "std::find() function: " << std::endl;
    PFArray<int>::IterInner it = std::find(fourth.begin(), fourth.end(), 4);
    std::cout << "Found 4 at index " << it - fourth.begin() << std::endl;

    // Test std::for_each function
    std::cout << "\nTest std::for_each() function: " << std::endl;
    std::for_each(fourth.begin(), fourth.end(), [](int x) { std::cout << x << std::endl; });

    std::cout << "\nchanging the values with:\nfourth[0]=31\nfourth[1]=29\nfourth[2]=5\n(for std::sort function)" << std::endl;
    fourth[0]=31;
    fourth[1]=29;
    fourth[2]=5;

    // Test std::sort function
    std::cout << "\nTest std::sort() function: " << std::endl;
    std::sort(fourth.begin(), fourth.end());
    for (auto x : fourth) {
        std::cout << x << std::endl;
    }

    return 0;
}
