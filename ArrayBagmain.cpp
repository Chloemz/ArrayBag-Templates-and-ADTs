
#include <iostream>
#include "ArrayBag.hpp"

int main(){
    ArrayBag<std::string> a;

    a.add("A");
    a.add("B");
    a.add("C");
    a.add("D");
    a.add("E");

    a.display();

    std::cout << '\n';

    /*a.duplicateItems();
    a.display();

    std::cout << '\n';

    a.removeDuplicates();
    a.display();

    std::cout << '\n';

    std::cout << "Frequency of A is " << a.getFrequencyOf("A") << "\n";
    std::cout << "Frequency of B is " << a.getFrequencyOf("B") << "\n";
    std::cout << "Frequency of C is " << a.getFrequencyOf("C") << "\n";
    std::cout << "Frequency of D is " << a.getFrequencyOf("D") << "\n";
    std::cout << "Frequency of E is " << a.getFrequencyOf("E") << "\n";*/

    ArrayBag<std::string> b;

    b.add("B");
    b.add("D");

    std::cout << '\n';

    b.display();

    std::cout << '\n';

    a/=b;   //a.operator/=(b) bag a will only have the elements in both a&b
    a.display();

    std::cout << '\n';

    std::cout << "Frequency of A is " << a.getFrequencyOf("A") << "\n";
    std::cout << "Frequency of B is " << a.getFrequencyOf("B") << "\n";
    std::cout << "Frequency of C is " << a.getFrequencyOf("C") << "\n";
    std::cout << "Frequency of D is " << a.getFrequencyOf("D") << "\n";
    std::cout << "Frequency of E is " << a.getFrequencyOf("E") << "\n";

    
};
/*int main(){
    ArrayBag<std::string> a;
    a.add("1");
    a.add("2");
    a.add("3");
    
    a.duplicateItems();
    a.display();

    std::cout << '\n';

    a.duplicateItems();
    a.display();

    std::cout << '\n';

    a.removeDuplicates();
    //a.remove("1");
    a.display();

    std::cout << '\n';
//new test
    ArrayBag<std::string> b;
    b.add("A");
    b.add("B");
    b.add("B");
    b.add("B");
    b.add("C");
    b.add("C");
    
    b.duplicateItems();
    b.display();

    std::cout << '\n';

    b.removeDuplicates();
    
    b.display();

    std::cout << '\n';
    

};*/