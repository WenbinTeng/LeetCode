#include <vector>

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) : big(big), medium(medium), small(small) {
    }

    bool addCar(int carType) {
        switch (carType) {
        case 1:
            if (big > 0) {
                --big;
                return true;
            } else
                return false;
        case 2:
            if (medium > 0) {
                --medium;
                return true;
            } else
                return false;
        case 3:
            if (small > 0) {
                --small;
                return true;
            } else
                return false;
        default:;
        }

        return false;
    }

    int big;
    int medium;
    int small;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */