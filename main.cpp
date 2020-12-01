#include <iostream>
#include <string>
#include "ArrayList.hpp"

int main() {
    ArrayList<int> numbers;
    numbers.placeBack(5);
    std::cout << "Before remove back: " << numbers.getSize() << std::endl;

    numbers.removeBack();
    std::cout << "After remove back: " << numbers.getSize() << std::endl;

    for (int i = 0; i < 10; i++) {
        numbers.placeBack(i);
    }
    std::cout << "Index 3: " << numbers.get(3) << std::endl;
    numbers.get(5) = 50;
    numbers[6] = 60;

    if (numbers.contains(8)){
        std::cout << "Contains 8" << std::endl;
    }

    if (!numbers.isEmpty()){
        std::cout << "Contains elements" << std::endl;
    }

    std::cout << "\"9\" is at index #" << numbers.indexOf(9) << std::endl;
    std::cout << "\"10\" is at index #" << numbers.indexOf(10) << std::endl;

    numbers.trim(7);
    std::cout << "New size after trim: " << numbers.getSize() << std::endl;


    int* intArr = numbers.toArray();
    std::cout << "Int Array: ";
    for (int i = 0; i < numbers.getSize(); i++){
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    numbers.insertAt(4, 367);
    std::cout << "Insert fifth: " << numbers << std::endl;
    numbers.removeAt(2);
    std::cout << "Remove third: " << numbers << std::endl;

    std::cout << std::endl;

    auto* stringArr = new std::string[9]{std::string("ABC"), std::string("DEF"), std::string("GHI"), std::string("JKL"), std::string("MNO"), std::string("PQR"), std::string("STU"), std::string("VWX"), std::string("Y&Z")};
    ArrayList<std::string> letters(stringArr, 9);
    std::cout << "Before clear: " << letters << std::endl;

    letters.clear();
    std::cout << "After clear: "<< letters << std::endl;

    std::cout << std::endl;

    bool boolArr[4] = {false, true, true, false};
    ArrayList<bool> boolTest = ArrayList<bool>(boolArr, 4);
    ArrayList<bool> boolCopyTest = boolTest;
    std::cout << "Copy constructor: " << boolCopyTest << std::endl;
    boolCopyTest = boolTest;
    std::cout << "Copy operator: " << boolCopyTest << std::endl;

    std::cout << std::endl;

    //Iterator testing
    auto itBegin = numbers.begin();
    auto itEnd = numbers.end();
    if (itBegin != itEnd){
        std::cout << "Array is not empty" << std::endl;
    }
    for (int num : numbers) {
        std::cout << "In foreach loop: " << num << std::endl;
    }
    numbers.replace(90, itBegin + 2, itEnd - 1);
    std::cout << "Replaced by Iterator: " << numbers << std::endl;

    return 0;

}
