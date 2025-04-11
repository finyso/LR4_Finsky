#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

template <typename T>
class Vector {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void reallocate(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i)
            new_data[i] = data_[i];
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    Vector() : data_(nullptr), size_(0), capacity_(0) {}
    Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i)
            data_[i] = other.data_[i];
    }

    ~Vector() {
        delete[] data_;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i)
                data_[i] = other.data_[i];
        }
        return *this;
    }

    T& operator[](size_t index) { return data_[index]; }
    const T& operator[](size_t index) const { return data_[index]; }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
            reallocate(new_capacity);
        }
        data_[size_++] = value;
    }

    void clear() { size_ = 0; }

    size_t size() const { return size_; }
};

#endif // VECTOR_H
