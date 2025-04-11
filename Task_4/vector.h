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

    // Доступ
    T& operator[](size_t index) { return data_[index]; }
    const T& operator[](size_t index) const { return data_[index]; }

    T& at(size_t index) {
        if (index >= size_ || index < 0) {
            return data_[0];
        }
        return data_[index];
    }

    const T& at(size_t index) const {
        if (index >= size_ || index < 0) {
            return data_[0];
        }
        return data_[index];
    }

    T& back() { return data_[size_ - 1]; }
    const T& back() const { return data_[size_ - 1]; }

    // Методы
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }

    size_t max_size() const {
        return static_cast<size_t>(-1) / sizeof(T);
    }

    bool empty() const { return size_ == 0; }

    void clear() { size_ = 0; }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            size_t new_capacity = capacity_ == 0 ? 1 : capacity_ + 1;
            reallocate(new_capacity);
        }
        data_[size_++] = value;
    }

    void pop_back() {
        if (size_ > 0)
            --size_;
    }

    void insert(size_t index, const T& value) {
        if (index > size_)
            return;
        if (size_ == capacity_) {
            size_t new_capacity = capacity_ == 0 ? 1 : capacity_ + 1;
            reallocate(new_capacity);
        }
        for (size_t i = size_; i > index; --i)
            data_[i] = data_[i - 1];
        data_[index] = value;
        ++size_;
    }

    void resize(size_t new_size) {
        if (new_size > capacity_)
            reallocate(new_size);
        size_ = new_size;
    }

    void assign(Vector& other) {
        if (this == &other) return;

        delete[] data_;

        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
    }


    void emplace(size_t index, const T& value) {
        insert(index, value);
    }

    void emplace_back(const T& value) {
        push_back(value);
    }

    void erase(size_t index) {
        if (index >= size_) return;
        for (size_t i = index; i + 1 < size_; ++i)
            data_[i] = data_[i + 1];
        --size_;
    }

    void erase(size_t from, size_t to) {
        if (from >= size_ || to > size_ || from >= to) return;
        size_t count = to - from;
        for (size_t i = from; i < size_ - count; ++i)
            data_[i] = data_[i + count];

        size_ -= count;
    }


    void swap(Vector& other) {
        T* temp_data = data_;
        data_ = other.data_;
        other.data_ = temp_data;

        size_t temp_size = size_;
        size_ = other.size_;
        other.size_ = temp_size;

        size_t temp_capacity = capacity_;
        capacity_ = other.capacity_;
        other.capacity_ = temp_capacity;
    }

    // Итераторы
    class Iterator {
    private:
        T* ptr_;
    public:
        Iterator(T* ptr = nullptr) : ptr_(ptr) {}

        T& operator*() { return *ptr_; }
        const T& operator*() const { return *ptr_; }

        Iterator& operator++() { ++ptr_; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++ptr_; return tmp; }

        Iterator& operator--() { --ptr_; return *this; }
        Iterator operator--(int) { Iterator tmp = *this; --ptr_; return tmp; }

        Iterator operator+(size_t n) const { return Iterator(ptr_ + n); }
        Iterator operator-(size_t n) const { return Iterator(ptr_ - n); }
        size_t operator-(const Iterator& other) const { return ptr_ - other.ptr_; }

        Iterator& operator+=(size_t n) { ptr_ += n; return *this; }
        Iterator& operator-=(size_t n) { ptr_ -= n; return *this; }

        T& operator[](size_t n) { return *(ptr_ + n); }

        bool operator==(const Iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const Iterator& other) const { return ptr_ != other.ptr_; }
        bool operator<(const Iterator& other) const { return ptr_ < other.ptr_; }
        bool operator>(const Iterator& other) const { return ptr_ > other.ptr_; }
        bool operator<=(const Iterator& other) const { return ptr_ <= other.ptr_; }
        bool operator>=(const Iterator& other) const { return ptr_ >= other.ptr_; }
    };

    Iterator begin() { return Iterator(data_); }
    Iterator end() { return Iterator(data_ + size_); }

    Iterator cbegin() const { return Iterator(data_); }
    Iterator cend() const { return Iterator(data_ + size_); }

    Iterator rbegin() { return Iterator(data_ + size_ - 1); }
    Iterator rend() { return Iterator(data_ - 1); }
    Iterator rbegin() const { return Iterator(data_ + size_ - 1); }
    Iterator rend() const { return Iterator(data_ - 1); }
};

#endif // VECTOR_H
