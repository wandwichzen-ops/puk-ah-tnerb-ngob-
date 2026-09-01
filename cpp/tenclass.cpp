#include <iostream>
#include <string>
#include <vector>
#include <memory>

// ==========================================
// 1. TOP-LEVEL SUPERCLASS
// ==========================================
class Vehicle {
protected:
    std::string brand;

public:
    virtual void getInput() {
        std::cout << "Enter Brand Name: ";
        std::getline(std::cin >> std::ws, brand);
    }

    virtual void showOutput() const {
        std::cout << "\nBrand: " << brand << std::endl;
    }

    virtual ~Vehicle() = default;
};

// ==========================================
// 2. MID-LEVEL SUBCLASS: LandVehicle
// ==========================================
class LandVehicle : public Vehicle {
protected:
    int maxSpeed;

public:
    void getInput() override {
        Vehicle::getInput();
        std::cout << "Enter Max Speed (km/h): ";
        std::cin >> maxSpeed;
    }

    void showOutput() const override {
        Vehicle::showOutput();
        std::cout << "Environment: Land | Max Speed: " << maxSpeed << " km/h" << std::endl;
    }
};

// ==========================================
// 3. SUBCLASS: WheeledVehicle
// ==========================================
class WheeledVehicle : public LandVehicle {
protected:
    int wheels;

public:
    void getInput() override {
        LandVehicle::getInput();
        std::cout << "Enter Number of Wheels: ";
        std::cin >> wheels;
    }

    void showOutput() const override {
        LandVehicle::showOutput();
        std::cout << "Wheels: " << wheels << std::endl;
    }
};

// ==========================================
// 4. LEAF SUBCLASS: Car
// ==========================================
class Car : public WheeledVehicle {
private:
    int doors;

public:
    void getInput() override {
        WheeledVehicle::getInput();
        std::cout << "Enter Number of Doors: ";
        std::cin >> doors;
    }

    void showOutput() const override {
        std::cout << "\n--- [CAR DETAILS] ---";
        WheeledVehicle::showOutput();
        std::cout << "Doors: " << doors << std::endl;
    }
};

// ==========================================
// 5. LEAF SUBCLASS: Truck
// ==========================================
class Truck : public WheeledVehicle {
private:
    double cargoCapacityTons;

public:
    void getInput() override {
        WheeledVehicle::getInput();
        std::cout << "Enter Cargo Capacity (Tons): ";
        std::cin >> cargoCapacityTons;
    }

    void showOutput() const override {
        std::cout << "\n--- [TRUCK DETAILS] ---";
        WheeledVehicle::showOutput();
        std::cout << "Cargo Capacity: " << cargoCapacityTons << " Tons" << std::endl;
    }
};

// ==========================================
// 6. SUBCLASS: TrackedVehicle
// ==========================================
class TrackedVehicle : public LandVehicle {
protected:
    double trackWidth;

public:
    void getInput() override {
        LandVehicle::getInput();
        std::cout << "Enter Track Width (cm): ";
        std::cin >> trackWidth;
    }

    void showOutput() const override {
        LandVehicle::showOutput();
        std::cout << "Track Width: " << trackWidth << " cm" << std::endl;
    }
};

// ==========================================
// 7. LEAF SUBCLASS: Tank
// ==========================================
class Tank : public TrackedVehicle {
private:
    int armorThicknessMm;

public:
    void getInput() override {
        TrackedVehicle::getInput();
        std::cout << "Enter Armor Thickness (mm): ";
        std::cin >> armorThicknessMm;
    }

    void showOutput() const override {
        std::cout << "\n--- [TANK DETAILS] ---";
        TrackedVehicle::showOutput();
        std::cout << "Armor Thickness: " << armorThicknessMm << " mm" << std::endl;
    }
};

// ==========================================
// 8. MID-LEVEL SUBCLASS: AirVehicle
// ==========================================
class AirVehicle : public Vehicle {
protected:
    double maxAltitudeMeters;

public:
    void getInput() override {
        Vehicle::getInput();
        std::cout << "Enter Max Altitude (Meters): ";
        std::cin >> maxAltitudeMeters;
    }

    void showOutput() const override {
        Vehicle::showOutput();
        std::cout << "Environment: Air | Max Altitude: " << maxAltitudeMeters << " m" << std::endl;
    }
};

// ==========================================
// 9. LEAF SUBCLASS: Airplane
// ==========================================
class Airplane : public AirVehicle {
private:
    int passengerSeats;

public:
    void getInput() override {
        AirVehicle::getInput();
        std::cout << "Enter Passenger Seats: ";
        std::cin >> passengerSeats;
    }

    void showOutput() const override {
        std::cout << "\n--- [AIRPLANE DETAILS] ---";
        AirVehicle::showOutput();
        std::cout << "Passenger Seats: " << passengerSeats << std::endl;
    }
};

// ==========================================
// 10. LEAF SUBCLASS: Helicopter
// ==========================================
class Helicopter : public AirVehicle {
private:
    int rotorCount;

public:
    void getInput() override {
        AirVehicle::getInput();
        std::cout << "Enter Number of Rotors: ";
        std::cin >> rotorCount;
    }

    void showOutput() const override {
        std::cout << "\n--- [HELICOPTER DETAILS] ---";
        AirVehicle::showOutput();
        std::cout << "Rotors: " << rotorCount << std::endl;
    }
};

// ==========================================
// MAIN FUNCTION (Polymorphic Menu System)
// ==========================================
int main() {
    std::vector<std::unique_ptr<Vehicle>> garage;
    int choice;

    std::cout << "=== VEHICLE MANAGEMENT SYSTEM ===\n";
    std::cout << "How many vehicles do you want to register? ";
    int total;
    std::cin >> total;

    for (int i = 0; i < total; ++i) {
        std::cout << "\nSelect Vehicle Type for #" << (i + 1) << ":\n";
        std::cout << "1. Car\n2. Truck\n3. Tank\n4. Airplane\n5. Helicopter\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        std::unique_ptr<Vehicle> v;

        switch (choice) {
            case 1: v = std::make_unique<Car>(); break;
            case 2: v = std::make_unique<Truck>(); break;
            case 3: v = std::make_unique<Tank>(); break;
            case 4: v = std::make_unique<Airplane>(); break;
            case 5: v = std::make_unique<Helicopter>(); break;
            default:
                std::cout << "Invalid choice! Skipping...\n";
                continue;
        }

        v->getInput();         // Polymorphic Input
        garage.push_back(std::move(v));
    }

    // Output phase using polymorphism
    std::cout << "\n=================================";
    std::cout << "\n  REGISTERED VEHICLES SUMMARY";
    std::cout << "\n=================================";
    for (const auto& vehicle : garage) {
        vehicle->showOutput(); // Polymorphic Output
    }

    return 0;
}