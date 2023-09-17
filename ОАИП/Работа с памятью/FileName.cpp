#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include <new>

class MyClass {
public:
    MyClass() { std::cout << "MyClass object has been created.\n"; }
    ~MyClass() { std::cout << "MyClass object has been destroyed.\n"; }

    void print() { std::cout << "Hello from MyClass object!\n"; }
};

// Function to demonstrate new operator
void new_operator_demo() {
    MyClass* obj = new MyClass;
    obj->print();
    delete obj;
}

// Function to demonstrate new operator with exception handling
void new_operator_exception_demo() {
    try {
        MyClass* obj = new (std::nothrow) MyClass[1000000000];  // This is an arbitrarily large number
        if (!obj) {
            throw std::bad_alloc();
        }
        // Do something with obj...

        delete[] obj;
    }
    catch (std::bad_alloc& ba) {
        std::cout << "Allocation failed: " << ba.what() << '\n';
    }
}

// Function to demonstrate unique_ptr
void unique_ptr_demo() {
    std::unique_ptr<MyClass> unique_obj = std::make_unique<MyClass>();
    unique_obj->print();
}

// Function to demonstrate shared_ptr
void shared_ptr_demo() {
    std::shared_ptr<MyClass> shared_obj1 = std::make_shared<MyClass>();
    shared_obj1->print();

    std::shared_ptr<MyClass> shared_obj2 = shared_obj1;
    shared_obj2->print();
}

// Function to demonstrate vector
void vector_demo() {
    std::vector<MyClass> my_vector;
    my_vector.push_back(MyClass());
    my_vector.back().print();
}

// Function to demonstrate array
void array_demo() {
    std::array<MyClass, 3> my_array;
    for (auto& obj : my_array) {
        obj.print();
    }
}

int main() {
    std::cout << "New operator demo:\n";
    new_operator_demo();

    std::cout << "\nNew operator with exception handling demo:\n";
    new_operator_exception_demo();

    std::cout << "\nUnique_ptr demo:\n";
    unique_ptr_demo();

    std::cout << "\nShared_ptr demo:\n";
    shared_ptr_demo();

    std::cout << "\nVector demo:\n";
    vector_demo();

    std::cout << "\nArray demo:\n";
    array_demo();

    return 0;
}
