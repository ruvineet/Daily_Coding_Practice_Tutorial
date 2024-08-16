#include <iostream>
#include <string>

#include <memory>

class Engine {
    private:
        std::string  type;
    public:
        Engine(std:: string t): type(t){}
        virtual void start() {
            std:: cout << " started the car "<<type << " " << std:: endl;
        }
        
        ~Engine() {
            std:: cout << " Engine stooped  " << std:: endl;
        }
};

class Car{
    private:
        std:: unique_ptr<Engine> engine =  nullptr;
        std:: string model; 
    public:
        Car(std:: string m1, std:: unique_ptr<Engine> e) : model(m1), engine(std:: move(e)) {}
        void start() {
        engine->start();
        }
};

int main() {
   // std:: unique_ptr<Engine> p2 = std:: make_unique<Engine>("bmw");
    std:: unique_ptr<Car> p1 = std:: make_unique<Car>(" aptiv ", std:: move(std::make_unique<Engine>("bmw")));
    p1->start();
    return 0;
}

