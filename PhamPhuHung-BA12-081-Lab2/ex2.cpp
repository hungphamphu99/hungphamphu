#include <iostream>

struct TrainCar {
    char id;
    int capacity;
    int passengers;
    TrainCar* next;

    TrainCar(char carid, int carcapacity) {
        id = carid;
        capacity = carcapacity;
        passengers = 0;
        next = nullptr;
    }
};

class Train {
private:
    TrainCar* head;
    int length;

public:
    Train() {
        head = nullptr;
        length = 0;
    }

    void addCar(char carid, int carcapacity) {
        TrainCar* newCar = new TrainCar(carid, carcapacity);
        newCar->next = head;
        head = newCar;
        length++;
    }

    void reservePassengers(char carid, int numPassengers) {
        TrainCar* current = head;
        while (current != nullptr) {
            if (current->id == carid) {
                int availableSeats = current->capacity - current->passengers;
                if (numPassengers <= availableSeats) {
                    current->passengers += numPassengers;
                    break;
                } else {
                    std::cout << "Not enough available seats in car " << carid << std::endl;
                    break;
                }
            }
            current = current->next;
        }
    }

    void removeEmptyCars() {
        TrainCar* current = head;
        TrainCar* previous = nullptr;
        
        while (current != nullptr) {
            if (current->passengers == 0) {
                if (previous != nullptr) {
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                } else {
                    head = current->next;
                    delete current;
                    current = head;
                }
                length--;
            } else {
                previous = current;
                current = current->next;
            }
        }
    }

    void displayTrainInfo() {
        TrainCar* current = head;
        std::cout << "Train Information:" << std::endl;
        while (current != nullptr) {
            std::cout << "Car " << current->id << ": Capacity = " << current->capacity << ", Passengers = " << current->passengers << std::endl;
            current = current->next;
        }
    }

    int getTrainLength() {
        return length;
    }
};

int main() {
    Train train;
    train.addCar('A', 40);
    train.addCar('B', 45);
    train.addCar('C', 30);
    train.addCar('D', 1);
    train.reservePassengers('A', 20);
    train.reservePassengers('B', 20);
    train.reservePassengers('C', 10);
    train.reservePassengers('A', 10);
    train.reservePassengers('D', 0);
    train.displayTrainInfo();
    train.removeEmptyCars();
    printf("\nAfter removing empty cars: \n");
    train.displayTrainInfo();
    
    int trainLength = train.getTrainLength();
    std::cout << "Train Length: " << trainLength << " cars" << std::endl;

    return 0;
}
