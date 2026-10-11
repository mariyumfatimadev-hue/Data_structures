#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>
class Queue
{
private:
    T* data;
    int frontIndex;
    int rearIndex;
    int count;
    int cap;

    void resize(int newCap)
    {
        T* temp = new T[newCap];
        for (int i = 0; i < count; i++)
        {
            temp[i] = data[(frontIndex + i) % cap];
        }
        delete[] data;
        data = temp;
        cap = newCap;
        frontIndex = 0;
        rearIndex = (count == 0) ? -1 : count - 1;
    }

public:
Queue(int initialCap = 10)
{
    cap = initialCap;
    count = 0;
    frontIndex = 0;
    rearIndex = -1;
    data = new T[cap];
}
    Queue(const Queue& other)
    {
        cap = other.cap;
        count = other.count;
        data = new T[cap];
        for (int i = 0; i < count; i++)
        {
            data[i] = other.data[(other.frontIndex + i) % other.cap];
        }
        frontIndex = 0;
        rearIndex = (count == 0) ? -1 : count - 1;
    }

    Queue& operator=(const Queue& other)
    {
        if (this != &other)
        {
            T* temp = new T[other.cap];
            for (int i = 0; i < other.count; i++)
            {
                temp[i] = other.data[(other.frontIndex + i) % other.cap];
            }
            delete[] data;
            data = temp;
            cap = other.cap;
            count = other.count;
            frontIndex = 0;
            rearIndex = (count == 0) ? -1 : count - 1;
        }
        return *this;
    }
if (isEmpty()) {
    throw std::underflow_error("Queue is empty");
}
T dequeue()
    {
        T value = data[frontIndex];
        frontIndex = (frontIndex + 1) % cap;
        count--;
        if (count == 0)
        {
            frontIndex = 0;
            rearIndex = -1;
        }
        return value;
    }

    ~Queue()
    {
        delete[] data;
    }

    void enqueue(const T& value)
    {
        if (isFull())
        {
            resize(cap * 2);
        }
        rearIndex = (rearIndex + 1) % cap;
        data[rearIndex] = value;
        count++;
    }

    
    T& front()
    {
        return data[frontIndex];
    }

    const T& front() const
    {
        return data[frontIndex];
    }

    T& rear()
    {
        return data[rearIndex];
    }

    const T& rear() const
    {
        return data[rearIndex];
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    bool isFull() const
    {
        return count == cap;
    }

    int size() const
    {
        return count;
    }

    int capacity() const
    {
        return cap;
    }

    void clear()
    {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool contains(const T& value) const
    {
        for (int i = 0; i < count; i++)
        {
            if (data[(frontIndex + i) % cap] == value)
            {
                return true;
            }
        }
        return false;
    }

    void reverse()
    {
        for (int i = 0; i < count / 2; i++)
        {
            int a = (frontIndex + i) % cap;
            int b = (frontIndex + count - 1 - i) % cap;
            T temp = data[a];
            data[a] = data[b];
            data[b] = temp;
        }
    }

    T& operator[](int index)
    {
        return data[(frontIndex + index) % cap];
    }

    const T& operator[](int index) const
    {
        return data[(frontIndex + index) % cap];
    }

    bool operator==(const Queue& other) const
    {
        if (count != other.count)
        {
            return false;
        }
        for (int i = 0; i < count; i++)
        {
            if (!(data[(frontIndex + i) % cap] == other.data[(other.frontIndex + i) % other.cap]))
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Queue& other) const
    {
        return !(*this == other);
    }

    void display() const
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        std::cout << "Front";
        for (int i = 0; i < count; i++)
        {
            std::cout << data[(frontIndex + i) % cap] << " ";
        }
        std::cout << "Rear" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue& q)
    {
        for (int i = 0; i < q.count; i++)
        {
            os << q.data[(q.frontIndex + i) % q.cap];
            if (i != q.count - 1)
            {
                os << " ";
            }
        }
        return os;
    }
};

#endif