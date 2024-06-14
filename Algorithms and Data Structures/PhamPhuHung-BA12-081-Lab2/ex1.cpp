#include <iostream>
#include <vector>

class UnboundedInteger {
private:
    int sign;
    std::vector<int> digits;

public:
    UnboundedInteger() {
        sign = 1; 
    }

    void addDigit(int digit) {
        digits.insert(digits.begin(), digit);
    }

    void removeDigit(int position) {
        if (position >= 0 && position < digits.size()) {
            digits.erase(digits.begin() + position);
        }
    }

    int calculateSum() {
        int sum = 0;
        for (int digit : digits) {
            sum += digit;
        }
        return sum * sign;
    }

    void display() {
        std::cout << "Unbounded Integer: ";
        if (sign == -1) {
            std::cout << "-";
        }
        for (int digit : digits) {
            std::cout << digit;
        }
        std::cout << std::endl;
    }
};

int main() {
    UnboundedInteger integer;
    integer.addDigit(3);
    integer.addDigit(5);
    integer.addDigit(7);
    integer.display();

    integer.removeDigit(1);
    integer.display();

    integer.addDigit(3);
    integer.display();

    int sum = integer.calculateSum();
    std::cout << "Sum of Digits: " << sum << std::endl;

    return 0;
}
