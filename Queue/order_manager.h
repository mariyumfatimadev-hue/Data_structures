#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <iostream>
#include "QUEUE_class.h"
#include "Order.h"

using namespace std;

class OrderManager {
private:
    Queue<Order> q;
    int timeQuantum;

public:
    OrderManager(Order arr[], int len, int tq) {
        timeQuantum = tq;
        for (int i = 0; i < len; i++) {
            q.enqueue(arr[i]);
        }
    }

    void processOrders() {
        int globalTimer = 0; 

        while (!q.isEmpty()) {
            Order currentOrder = q.dequeue();

            cout << "Processing Order ID: " << currentOrder.getId() 
                 << ", Customer: " << currentOrder.getName() 
                 << ", Remaining Time: " << currentOrder.getPreparationTime() << " units" << endl;

            int timeToProcess = (currentOrder.getPreparationTime() < timeQuantum) 
                                ? currentOrder.getPreparationTime() 
                                : timeQuantum;

            for (int t = 0; t < timeToProcess; t++) {
                globalTimer++;
            }

            int remainingTime = currentOrder.getPreparationTime() - timeToProcess;
            currentOrder.setPreparationTime(remainingTime);

            if (currentOrder.getPreparationTime() == 0) {
                cout << "Order (" << currentOrder.getId() << ", " << currentOrder.getName() << ") completed preparation" << endl;
            } else {
                q.enqueue(currentOrder);
            }
        }

        cout << "\nAll orders have been completely prepared! Total simulation time: " << globalTimer << " units." << endl;
    }
};

#endif