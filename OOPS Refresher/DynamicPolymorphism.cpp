#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m)
    {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void stopEngine()
    {
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off!" << endl;
    }

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual ~Car() {}
};

class ManualCar : public Car
{
private:
    int currentGear;

public:
    ManualCar(string b, string m) : Car(b, m)
    {
        currentGear = 0;
    }

    void shiftGear(int gear)
    {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void accelerate(){
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }

        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake(){
         currentSpeed -= 20;
        if (currentSpeed < 0)
            currentSpeed = 0;

        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }
};

class ElectricCar : public Car
{
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b, m)
    {
        batteryLevel = 100;
    }

    void chargeBattery()
    {
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery fully charged!" << endl;
    }

    void accelerate(){
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }

        if(batteryLevel <= 0){
            cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
        }

        batteryLevel -= 10;
        currentSpeed += 15;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. Battery at " << batteryLevel << "%. " << endl;
    }

    void brake(){
         currentSpeed -= 15;
        if (currentSpeed < 0)
            currentSpeed = 0;

        cout << brand << " " << model << " : Regenerative braking! Speed is now " << currentSpeed << " km/h. Battery at " << batteryLevel << "%. " << endl;
    }
};

int main()
{

    Car *myManualCar = new ManualCar("Suzuki", "WagonR");

    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();


    cout << "-------------------" << endl;


    Car *myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    delete myManualCar;
    delete myElectricCar;

    return 0;
}