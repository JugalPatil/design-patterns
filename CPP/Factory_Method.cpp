#include <iostream>
#include <string>

class Product {
  public:
    virtual ~Product() {
        std::cout << "Product destructor base type" << std::endl;
    }

    virtual std::string create_product() = 0;
};

class ConcreteProductA : public Product {
  public:
    ConcreteProductA() {
        std::cout << "Product A constructor" << std::endl;
    }
    ~ConcreteProductA() {
        std::cout << "Product A destructor" << std::endl;
    }
    std::string create_product() override {
        return "Product created of A type";
    }
};

class ConcreteProductB : public Product {
  public:
    ConcreteProductB() {
        std::cout << "Product B constructor" << std::endl;
    }
    ~ConcreteProductB() {
        std::cout << "Product B destructor" << std::endl;
    }
    std::string create_product() override {
        return "Product created of B type";
    }
};

class Creator {
  public:
    virtual ~Creator() {
        std::cout << "Creator destructor base type" << std::endl;
    }

    virtual Product* factory_method() = 0;

    std::string operation() {
        Product* prod = this->factory_method();
        std::string result = "creator doing operation : " + prod->create_product();
        delete prod;
        return result;
    }
};

class ConcreteCreatorA : public Creator {
  public:
    ConcreteCreatorA(){
        std::cout << "creator A constructor" << std::endl;
    }
    ~ConcreteCreatorA(){
        std::cout << "creator A destructor" << std::endl;
    }
    Product* factory_method() override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
  public:
    ConcreteCreatorB(){
        std::cout << "creator B constructor" << std::endl;
    }    
    ~ConcreteCreatorB(){
        std::cout << "creator B destructor" << std::endl;
    }
    Product* factory_method() override {
        return new ConcreteProductB();
    }
};

void user(Creator *creator) {
    std::cout << "calling the creator" << std::endl;
    std::string res = creator->operation();
    std::cout << res << std::endl;
}

int main() {
    Creator* creator1 = new ConcreteCreatorA();
    user(creator1);
    std::cout << std::endl;

    Creator* creator2 = new ConcreteCreatorB();
    user(creator2);
    std::cout << std::endl;
    
    delete creator1;
    delete creator2;

    return 0;
}

