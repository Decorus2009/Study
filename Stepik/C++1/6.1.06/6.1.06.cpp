#include <cstddef>
#include <algorithm>

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T()) : data_(new T[size]), size_(size) {
        std::fill_n(data_, size, value);
    }
    Array(const Array &that) : data_(new T[that.size_]), size_(that.size_) {
        std::copy(that.data_, that.data_ + that.size_, data_);
    }
    ~Array() {
        delete [] data_;
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
