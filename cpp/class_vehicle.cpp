#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>

using namespace std;

class Vehicle
{
protected:
    string name;

public:
    virtual void getInput()
    {
        cout << "Enter Vehicle Name: ";
        getline(cin, name);
    }

    virtual void showOutput() const
    {
        cout << "\n--- Vehicle Details ---\n";
        cout << "Name: " << name << endl;
    }

    virtual ~Vehicle() = default;
};

class LandVehicle : public Vehicle
{
private:
    int numberOfWheels;

public:
    void getInput() override
    {
        Vehicle::getInput();
        cout << "Enter Number of Wheels: ";
        cin >> numberOfWheels;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void showOutput() const override
    {
        Vehicle::showOutput();
        cout << "Type: Land Vehicle\n";
        cout << "Wheels: " << numberOfWheels << endl;
    }
};

class AirVehicle : public Vehicle
{
private:
    double maxAltitude;

public:
    void getInput() override
    {
        Vehicle::getInput();
        cout << "Enter Max Altitude (in meters): ";
        cin >> maxAltitude;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void showOutput() const override
    {
        Vehicle::showOutput();
        cout << "Type: Air Vehicle\n";
        cout << "Max Altitude: " << maxAltitude << " m" << endl;
    }
};

int main()
{
    int choice;
    unique_ptr<Vehicle> myVehicle;

    cout << "Choose Vehicle Type (1: Land, 2: Air): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 1)
    {
        myVehicle = make_unique<LandVehicle>();
    } 
    else if (choice == 2)
    {
        myVehicle = make_unique<AirVehicle>();
    }
    else
    {
        cout << "Invalid choice!\n";
        return 1;
    }

    myVehicle->getInput();
    myVehicle->showOutput();

    return 0;
}