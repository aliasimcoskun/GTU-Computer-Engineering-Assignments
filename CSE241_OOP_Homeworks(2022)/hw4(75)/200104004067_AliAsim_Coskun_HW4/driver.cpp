#include "DoY.h"

using namespace DAY_OF_YEAR;

int main() {

    // Test default constructor
    DayofYearSet set1;
    std::cout << "\nset1 (default constructor): " << set1;
    DayofYearSet set10;
    std::cout << "\nset10 (default constructor): " << set10 << std::endl;

    // Test initializer list constructor
    DayofYearSet set2 = { DayofYearSet::DayOfYear(31, 1), DayofYearSet::DayOfYear(14, 2), DayofYearSet::DayOfYear(30, 6) };
    std::cout << "\nset2 (initializer list constructor): " << set2;
    DayofYearSet set11 = { DayofYearSet::DayOfYear(11, 1), DayofYearSet::DayOfYear(12, 2), DayofYearSet::DayOfYear(13, 3), DayofYearSet::DayOfYear(14, 4), 
    DayofYearSet::DayOfYear(15, 5), DayofYearSet::DayOfYear(16, 6), DayofYearSet::DayOfYear(17, 7), DayofYearSet::DayOfYear(18, 8), DayofYearSet::DayOfYear(19, 9), 
    DayofYearSet::DayOfYear(20, 10), DayofYearSet::DayOfYear(21, 11), DayofYearSet::DayOfYear(22, 12) };
    std::cout << "\nset11 (initializer list constructor): " << set11 << std::endl;

    // Test copy constructor
    DayofYearSet set3(set2);
    std::cout << "\nset3(set2) (copy constructor): " << set3;
    DayofYearSet set12(set11);
    std::cout << "\nset12(set11) (copy constructor): " << set12 << std::endl;

    // Test + operator
    set2 + DayofYearSet::DayOfYear(28, 12);
    std::cout << "\nset2 (Added 28 December by using operator+): " << set2;
    set2 + DayofYearSet::DayOfYear(29, 12);
    std::cout << "\nset2 (Added 29 December by using operator+): " << set2 << std::endl;

    // Test assignment operator
    set1 = set2;
    std::cout << "\nset1 = set2 (assignment operator): " << set1;
    set10 = set1;
    std::cout << "\nset10 = set1 (assignment operator): " << set10 << std::endl;

    // Test add function and overloaded output operator
    set1.add(DayofYearSet::DayOfYear(31, 12));
    std::cout << "\nset1 (after adding 31st December by using add function): " << set1;
    set1.add(DayofYearSet::DayOfYear(30,1));
    std::cout << "\nset1 (after adding 30th January by using add function): " << set1 << std::endl;

    // Test overloaded equality operator
    std::cout << "\nTest overloaded equality operator:";
    std::cout << "\nset2 == set3: " << (set2 == set3 ? "true" : "false");
    std::cout << "\nset2 == set1: " << (set2 == set1 ? "true" : "false") << std::endl;

    // Test overloaded inequality operator
    std::cout << "\n Test overloaded inequality operator:";
    std::cout << "\nset2 != set3: " << (set2 != set3 ? "true" : "false");
    std::cout << "\nset2 != set1: " << (set2 != set1 ? "true" : "false") << std::endl;

    std::cout << "\nREMINDER:\nset1: " << set1 << std::endl;
    std::cout << "set2: " << set2 << std::endl;
    std::cout << "set3: " << set3 << std::endl;

    // Test + and - operators
    std::cout << "\nTest + and - operators:";
    DayofYearSet set6 = (set2 + set1);
    std::cout << "\nset6 = set2 + set1: " << set6;
    DayofYearSet set7 = (set3 - set2);
    std::cout << "\nset7 = set3 - set2: " << set7 << std::endl;
    
    // Test overloaded intersection operator
    std::cout << "\nTest overloaded intersection operator:";
    DayofYearSet set4 = set1 ^ set3;
    std::cout << "\nset4 (set1 ^ set3): " << set4;
    DayofYearSet set9 = set6 ^ set3;
    std::cout << "\nset9 (set6 ^ set3): " << set9 << std::endl;

    // Test overloaded complement operator
    std::cout << "\nTest overloaded complement operator:";
    DayofYearSet set5 = !set4;
    std::cout << "\nset5 (!set4): " << set5;
    DayofYearSet set8 = !set5;
    std::cout << "\nset8 (!set5): " << set8 << std::endl;

    // Test overloaded subscript operator
    std::cout << "\nTest overloaded subscript operator:";
    std::cout << "\nset4[2]: " << set4[2].monthName() << " " << set4[2].day();
    std::cout << "\nset5[13]: " <<  set5[13].monthName() << " " << set5[13].day() << std::endl;

    // Test writing set to file
    std::ofstream out("set.txt");
    out << set4;
    out.close();
    std::cout << "\nREMINDER:\nset4: " << set4;
    std::cout << "\nset4 has written in the text file." << std::endl;

    return 0;
}