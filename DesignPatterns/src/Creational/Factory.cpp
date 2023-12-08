#include "Factory.h"


std::string ConcreteProduct1::Operation() const
{
    return "Product1";
}

std::string ConcreteProduct2::Operation() const
{
    return "Product2";
}

std::string Creator::SomeOperation() const
{
    Product* product = this->FactoryMethod();
    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
    delete product;
    return result;
}

Product* ConcreteCreator1::FactoryMethod() const
{
    return new ConcreteProduct1();
}

Product* ConcreteCreator2::FactoryMethod() const
{
    return new ConcreteProduct2();
}

void ClientCode(const Creator& creator)
{
    std::cout   << "Client: I'm not aware of the creator's class, but it still works.\n"
                << creator.SomeOperation() << std::endl;
}


void FactoryMain() {
    std::cout << "App: Launched with the ConreteCreator1.\n";
    Creator* creator = new ConcreteCreator1();
    ClientCode(*creator);
    std::cout << std::endl;

    std::cout << "App: Launched with the ConreteCreator2.\n";
    Creator* creator2 = new ConcreteCreator2();
    ClientCode(*creator2);
    std::cout << std::endl;

    delete creator;
    delete creator2;

}