#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <vector>

class Singleton {
  private:
    static std::shared_ptr<Singleton> obj;
    Singleton() {
        name++;
        std::cout << "constr called" << std::endl;
    }

  public:
    static int name;
    static std::shared_ptr<Singleton> get_obj();
};
std::mutex singleton_mutex;
std::shared_ptr<Singleton> Singleton::obj = nullptr;
int Singleton::name;

std::shared_ptr<Singleton> Singleton::get_obj() {
    if (obj) {
        // std::cout << "obj already present" << std::endl;
        return obj;
    }
    // const std::lock_guard<std::mutex> lock(singleton_mutex);
    // if (obj) return obj;
    // std::cout << "obj created" << std::endl;    
    obj.reset(new Singleton());
    return obj;
}

void thread_func() { 
    auto s1 = Singleton::get_obj();
    std::cout << "name : " << s1->name << std::endl;
}

int main() {
    // std::shared_ptr<Singleton> obj1(Singleton::get_obj());
    // std::shared_ptr<Singleton> obj2(Singleton::get_obj());
    // std::shared_ptr<Singleton> obj3(Singleton::get_obj());
    // std::shared_ptr<Singleton> obj4(Singleton::get_obj());
    // std::shared_ptr<Singleton> s1 = Singleton::get_obj();
    // std::shared_ptr<Singleton> s2 = Singleton::get_obj();
    // std::cout << "before update : "  << s2.get()->name << " , " << s1.get()->name << " , count : " << s1.use_count() << std::endl;
    // std::shared_ptr<Singleton> s3 = Singleton::get_obj();
    // std::shared_ptr<Singleton> s4 = Singleton::get_obj();
    // std::shared_ptr<Singleton> s5 = Singleton::get_obj();
    // std::shared_ptr<Singleton> s6 = Singleton::get_obj();
    // s1.get()->name = "jugal hushar";
    // std::cout << "after update : " << s2.get()->name << " , " << s1.get()->name << " , count : " << s1.use_count() <<std::endl;
    // Singleton::get_obj();
    // Singleton::get_obj();
    // Singleton::get_obj();

    std::vector<std::thread> threads;
    for (int i = 0; i < 99; i++) {
        threads.push_back(std::thread(thread_func));
    }

    for (int i = 0; i < 99; i++) {
        threads[i].join();
    }
    return 0;
}