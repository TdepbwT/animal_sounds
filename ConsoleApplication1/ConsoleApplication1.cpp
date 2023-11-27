#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr

using namespace std;

class Animal { // base class
public:
    virtual void speak() = 0; 
    virtual ~Animal() {}
};

class Sheep : public Animal { // sheep class, derived from Animal
public:
    void speak() override { // override pure virtual function
        cout << "Sheep says: \t\tbaa!" << endl;
    }
};

class Cow : public Animal { // cow class, derived from Animal
public:
    void speak() override {
        cout << "Cow says: \t\tmoo!" << endl;
    }
};

class Frisian : public Cow { // frisian class, derived from cow
public:
    void speak() override {
        cout << "Frisian Cow says: \tmoo (in black and white)!" << endl;
    }
};

// main function

int main() {
    vector<unique_ptr<Animal>> animals; 
    // create number of animals
    int numObjects;
    cout << "Enter the number of animals to create: "; // ask user for number of animals
    cin >> numObjects;

    
    for (int i = 0; i < numObjects; ++i) { // for loop to create number of animals
        int choice;
        cout << "Choose the object type (1 - Sheep, 2 - Cow, 3 - Frisian): ";
        cin >> choice;

        switch (choice) {
        case 1:
            animals.push_back(make_unique<Sheep>()); // add animal to vector
            break;
        case 2:
            animals.push_back(make_unique<Cow>());
            break;
        case 3:
            animals.push_back(make_unique<Frisian>());
            break;
        default:
            cout << "Invalid choice. Try again." << endl; // handle invalid choice
            --i; 
            break;
        }
    }

    
    for (const auto& animal : animals) { // output animal sounds
        animal->speak();
    }

    return 0;
}