#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Subscriber;

class Publisher {
  protected:
    int                      product_id;
    std::string              product_name;
    std::vector<Subscriber*> product_subscribers;

    Publisher(int id, std::string name) : product_id(id), product_name(name) {}

  public:
    virtual ~Publisher() {};
    virtual std::string product_info()                             = 0;
    virtual void product_subscriber_add(Subscriber* subscriber)    = 0;
    virtual void product_subscriber_remove(Subscriber* subscriber) = 0;
    virtual void notify_subscriber(std::string message)            = 0;
};

class Subscriber {
  private:
    int         subscriber_id;
    std::string subscriber_name;

  public:
    Subscriber(int id, std::string name) : subscriber_id(id), subscriber_name(name) {}

    void update(Publisher* publisher, std::string message) {
        std::cout << "Message from Publisher " 
                  << publisher->product_info() << " ==> " 
                  << message << std::endl;
    }

};

class Product : public Publisher {
  public:
    Product (int id, std::string name) : Publisher(id, name) {}
    ~Product () {};

    std::string product_info() override {
        std::string res = "Product id : "     + std::to_string(this->product_id) 
                        + ", Product Name : " + this->product_name;

        return res;
    }

    void product_subscriber_add(Subscriber* subscriber) override {
        product_subscribers.push_back(subscriber);
    }

    void product_subscriber_remove(Subscriber* subscriber) override {
        auto it = std::find(product_subscribers.begin(), product_subscribers.end(), subscriber);
        if (it != product_subscribers.end()) 
            product_subscribers.erase(it);
        else
            std::cout << "No such Subscriber found for Product skipping operation" << std::endl; 
    }

    void notify_subscriber(std::string message) override {
        std::cout << "Notifying all " << product_subscribers.size() << "subscribers" << std::endl;
        for (Subscriber* subscriber : product_subscribers) {
            subscriber->update(this, message);
        }
    }

};

int main() {
    Product prod1(14, "Iphone 14");
    Product prod2(22, "S22 ultra");
    Product prod3(7, "Pixel 7");

    std::vector<Subscriber*> subscribers(10); 
    int id = 1;

    for (Subscriber* sub : subscribers) {
        sub = new Subscriber(id, "jugal" + std::to_string(id));
        id++;
    }

    for (int i = 0; i < 10; i++) {
        prod1.product_subscriber_add(subscribers[i]);
        if (!(i & 1)) prod2.product_subscriber_add(subscribers[i]);
        if (i % 3 == 0) prod3.product_subscriber_add(subscribers[i]);
    }

    prod1.notify_subscriber("Cost updated for prod1");
    prod2.notify_subscriber("prod2 is now avilable");
    prod3.notify_subscriber("Happy Diwali");

}

