#ifndef ORDER_H
#define ORDER_H

#include <string>
using namespace std
class Order {
private:
    int orderId;
    std::string customerName;
    int preparationTime;

public:
    Order() {
        orderId = 0;
        customerName = "";
        preparationTime = 0;
    }

    Order(int id, std::string name, int time) {
        orderId = id;
        customerName = name;
        preparationTime = time;
    }

    int getId() const {
        return orderId;
    }

    std::string getName() const {
        return customerName;
    }

    int getPreparationTime() const {
        return preparationTime;
    }

    void setPreparationTime(int t) {
        preparationTime = t;
    }
};

#endif