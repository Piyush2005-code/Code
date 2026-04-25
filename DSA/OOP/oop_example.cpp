#include <iostream> // Required for input/output operations (like std::cout, std::cin)
#include <string>   // Required for using std::string

// -----------------------------------------------------------------------------------
// 1. Encapsulation: Bundling data (attributes) and methods (functions) that operate
//    on the data within a single unit, a "class". It also involves restricting
//    direct access to some of an object's components, typically through access specifiers.
// -----------------------------------------------------------------------------------

// Base Class: Vehicle
class Vehicle {
private:
    // Private attributes: These can only be accessed from within the Vehicle class.
    // This demonstrates data hiding, a core aspect of encapsulation.
    std::string make;
    std::string model;
    int year;
    double speed;

protected:
    // Protected attributes: These can be accessed within the Vehicle class and by
    // derived classes (like Car or Motorcycle).
    int numberOfWheels;

public:
    // Public constructor: A special method called when an object of the class is created.
    // It initializes the object's attributes.
    Vehicle(std::string mk, std::string mdl, int yr, int wheels)
        : make(mk), model(mdl), year(yr), numberOfWheels(wheels), speed(0.0) {
        std::cout << "Vehicle created: " << make << " " << model << std::endl;
    }

    // Public methods (Getters and Setters): These provide controlled access to
    // the private attributes, demonstrating how encapsulation allows managing data access.

    std::string getMake() const { // 'const' means this method doesn't modify object state
        return make;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    int getNumberOfWheels() const {
        return numberOfWheels;
    }

    double getSpeed() const {
        return speed;
    }

    void accelerate(double amount) {
        if (amount > 0) {
            speed += amount;
            std::cout << make << " " << model << " accelerated to " << speed << " km/h." << std::endl;
        }
    }

    void brake(double amount) {
        if (amount > 0 && speed - amount >= 0) {
            speed -= amount;
            std::cout << make << " " << model << " braked to " << speed << " km/h." << std::endl;
        } else if (speed - amount < 0) {
            speed = 0;
            std::cout << make << " " << model << " stopped." << std::endl;
        }
    }

    // Public method: Common behavior for all vehicles.
    void displayInfo() const {
        std::cout << "--- Vehicle Info ---" << std::endl;
        std::cout << "Make: " << make << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Wheels: " << numberOfWheels << std::endl;
        std::cout << "Current Speed: " << speed << " km/h" << std::endl;
    }

    // Virtual function: Essential for Polymorphism.
    // 'virtual' keyword indicates that this function can be overridden by derived classes.
    // '= 0' makes it a pure virtual function, making Vehicle an "abstract class".
    // An abstract class cannot be instantiated directly. It forces derived classes
    // to provide their own implementation for this method.
    virtual void startEngine() = 0;

    // Virtual destructor: Important for proper memory deallocation when deleting
    // objects through base class pointers (related to polymorphism).
    virtual ~Vehicle() {
        std::cout << "Vehicle destructor called for " << make << " " << model << std::endl;
    }
};

// -----------------------------------------------------------------------------------
// 2. Abstraction: Hiding the complex implementation details and showing only the
//    necessary features of an object. Here, the 'Vehicle' class is an abstract class
//    because it has a pure virtual function (startEngine()). Users of 'Vehicle'
//    objects (like through pointers) only need to know about its public interface
//    (displayInfo, accelerate, brake, startEngine), not the internal workings.
// -----------------------------------------------------------------------------------

// -----------------------------------------------------------------------------------
// 3. Inheritance: A mechanism where a new class (derived class) is created from
//    an existing class (base class). The derived class inherits attributes and
//    behaviors (methods) of the base class, promoting code reusability.
// -----------------------------------------------------------------------------------

// Derived Class: Car (inherits from Vehicle)
// 'public Vehicle' means public and protected members of Vehicle remain public/protected
// in Car, and private members are inaccessible.
class Car : public Vehicle {
private:
    int numberOfDoors; // Car-specific attribute

public:
    // Constructor for Car: Calls the base class (Vehicle) constructor using an initializer list.
    Car(std::string mk, std::string mdl, int yr, int doors)
        : Vehicle(mk, mdl, yr, 4), numberOfDoors(doors) { // Cars typically have 4 wheels
        std::cout << "Car created: " << getMake() << " " << getModel() << std::endl;
    }

    // Overriding the virtual function from the base class.
    // 'override' keyword is good practice for clarity and compiler checks.
    void startEngine() override {
        std::cout << getMake() << " " << getModel() << " engine started with a smooth hum." << std::endl;
    }

    // Car-specific method
    void openTrunk() {
        std::cout << getMake() << " " << getModel() << " trunk opened." << std::endl;
    }

    // Demonstrate access to protected member from base class
    void honk() {
        std::cout << getMake() << " " << getModel() << " honks! (It has " << numberOfWheels << " wheels)." << std::endl;
    }

    // Destructor for Car
    ~Car() override { // Also override destructor if base has virtual destructor
        std::cout << "Car destructor called for " << getMake() << " " << getModel() << std::endl;
    }
};

// Another Derived Class: Motorcycle (inherits from Vehicle)
class Motorcycle : public Vehicle {
private:
    bool hasSidecar; // Motorcycle-specific attribute

public:
    // Constructor for Motorcycle
    Motorcycle(std::string mk, std::string mdl, int yr, bool sidecar)
        : Vehicle(mk, mdl, yr, 2), hasSidecar(sidecar) { // Motorcycles typically have 2 wheels
        std::cout << "Motorcycle created: " << getMake() << " " << getModel() << std::endl;
    }

    // Overriding the virtual function for Motorcycle
    void startEngine() override {
        std::cout << getMake() << " " << getModel() << " engine roared to life!" << std::endl;
    }

    // Motorcycle-specific method
    void wheelie() {
        std::cout << getMake() << " " << getModel() << " performed a wheelie!" << std::endl;
    }

    // Destructor for Motorcycle
    ~Motorcycle() override {
        std::cout << "Motorcycle destructor called for " << getMake() << " " << getModel() << std::endl;
    }
};

// -----------------------------------------------------------------------------------
// 4. Polymorphism: The ability of an object to take on many forms. In C++, this
//    is primarily achieved through virtual functions and base class pointers/references.
//    It allows you to treat objects of different classes that are related by inheritance
//    through a common interface (the base class).
//
//    Another form of polymorphism is function overloading (compile-time polymorphism),
//    where multiple functions have the same name but different parameters.
// -----------------------------------------------------------------------------------

// Function Overloading (Compile-time Polymorphism)
// Two functions named 'processVehicle', but they take different types of arguments.
void processVehicle(Car& car) {
    std::cout << "\nProcessing a Car object (Function Overloading):" << std::endl;
    car.startEngine();
    car.accelerate(50);
    car.openTrunk();
    car.displayInfo();
}

void processVehicle(Motorcycle& moto) {
    std::cout << "\nProcessing a Motorcycle object (Function Overloading):" << std::endl;
    moto.startEngine();
    moto.accelerate(70);
    moto.wheelie();
    moto.displayInfo();
}

// Main function: Entry point of the program
int main() {
    std::cout << "--- Demonstrating OOP Concepts in C++ ---" << std::endl;

    // --- Encapsulation & Basic Usage ---
    std::cout << "\n--- Encapsulation & Basic Usage ---" << std::endl;
    // Creating an object of Car class
    Car myCar("Toyota", "Camry", 2023, 4);
    myCar.displayInfo(); // Accessing public methods
    myCar.accelerate(30);
    myCar.brake(10);
    myCar.openTrunk();
    myCar.honk(); // Accessing method that uses protected member

    // Attempting to access private members directly will result in a compile-time error:
    // myCar.make = "Honda"; // Error: 'make' is private

    std::cout << std::endl;

    // Creating an object of Motorcycle class
    Motorcycle myMotorcycle("Harley-Davidson", "Iron 883", 2022, false);
    myMotorcycle.displayInfo();
    myMotorcycle.accelerate(40);
    myMotorcycle.wheelie();

    // --- Inheritance Demonstration ---
    std::cout << "\n--- Inheritance Demonstration ---" << std::endl;
    // Both Car and Motorcycle objects have properties and behaviors from Vehicle
    // (like make, model, year, accelerate, brake, displayInfo) due to inheritance.

    // --- Abstraction Demonstration ---
    std::cout << "\n--- Abstraction Demonstration ---" << std::endl;
    // We cannot create an object of the abstract class Vehicle directly:
    // Vehicle someVehicle("Abstract", "Test", 2000, 4); // Error: cannot instantiate abstract class

    // We interact with derived classes, and 'startEngine' is abstract, meaning
    // each derived class *must* provide its own implementation.
    myCar.startEngine();
    myMotorcycle.startEngine();

    // --- Polymorphism (Runtime - using Virtual Functions) ---
    std::cout << "\n--- Polymorphism (Runtime) ---" << std::endl;

    // Using base class pointers to point to derived class objects.
    // This is where runtime polymorphism shines.
    Vehicle* v1 = &myCar;
    Vehicle* v2 = &myMotorcycle;

    // When startEngine() is called via a Vehicle pointer, the *correct*
    // derived class's version of startEngine() is called due to 'virtual' keyword.
    // This is dynamic dispatch or runtime polymorphism.
    v1->startEngine();      // Calls Car::startEngine()
    v2->startEngine();      // Calls Motorcycle::startEngine()

    v1->displayInfo();
    v2->displayInfo();

    // You can also put them in a container of base class pointers/references
    std::cout << "\n--- Polymorphism with a container ---" << std::endl;
    Vehicle* vehicles[2];
    vehicles[0] = new Car("Ford", "Mustang", 2024, 2);
    vehicles[1] = new Motorcycle("BMW", "R 1250 GS", 2023, true);

    for (int i = 0; i < 2; ++i) {
        vehicles[i]->displayInfo();
        vehicles[i]->startEngine();
        vehicles[i]->accelerate(60);
        std::cout << std::endl;
    }

    // Remember to free memory allocated with 'new'
    delete vehicles[0];
    delete vehicles[1];

    // --- Polymorphism (Compile-time - Function Overloading) ---
    std::cout << "\n--- Polymorphism (Compile-time - Function Overloading) ---" << std::endl;
    // The compiler determines which 'processVehicle' function to call based on the
    // type of the argument passed.
    processVehicle(myCar);
    processVehicle(myMotorcycle);

    std::cout << "\n--- End of Program ---" << std::endl;

    return 0; // Indicate successful execution
}