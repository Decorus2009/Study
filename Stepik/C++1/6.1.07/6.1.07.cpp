#include <cstddef>
#include <algorithm>

template <typename T>
class Array
{
public:
    explicit Array(size_t size, const T& value) {
        size_ = size;
        data_ = (T *) new char[size_ * sizeof(T)];
        for (size_t i = 0; i < size_; ++i) {
            new (data_ + i) T(value);
        }
    }
    Array() : data_(0), size_(0) {}
    Array(const Array &that) {
        size_ = that.size_;
        data_ = (T *) new char[size_ * sizeof(T)];
        for (size_t i = 0; i < size_; ++i) {
            new (data_ + i) T(that.data_[i]);
        }
    }
    ~Array() {
        for (size_t i = 0; i < size_; ++i) {
            data_[i].~T();
        }
        delete [] (char *) data_;
        data_ = 0;
    }
    Array& operator=(const Array &that) {
        if (this != &that) {
            Array(that).swap(*this);
        }
        return *this;
    }
    size_t size() const {
        return size_;
    }
    T& operator[](size_t i) {
        return data_[i];
    }
    const T& operator[](size_t i) const {
        return data_[i];
    }

private:
    T *data_;
    size_t size_;

    void swap(Array &that) {
        std::swap(data_, that.data_);
        std::swap(size_, that.size_);
    }
};
