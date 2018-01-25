struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = 0) : ptr_(ptr), counter_(ptr_ ? new size_t(1) : 0) {}
    ~SharedPtr() {
        decrease_counter_and_free_if_allowed();
    }
    SharedPtr(const SharedPtr &ptr) : ptr_(ptr.ptr_), counter_(ptr.counter_) {
        if (ptr_) {
            ++*counter_;
        }
    }
    SharedPtr& operator=(const SharedPtr &ptr) {
        if (this != &ptr) {
            if (ptr.ptr_) {
                ++*ptr.counter_;
            }
            decrease_counter_and_free_if_allowed();
            ptr_ = ptr.ptr_;
            counter_ = ptr.counter_;
        }
        return *this;
    }
    Expression* get() const {
        return ptr_;
    }
    void reset(Expression *ptr = 0) {
        decrease_counter_and_free_if_allowed();
        ptr_ = ptr;
        counter_ = ptr_ ? new size_t(1) : 0;
    }
    Expression& operator*() const {
        return *ptr_;
    }
    Expression* operator->() const {
        return ptr_;
    }

private:
    void decrease_counter_and_free_if_allowed() {
        if (ptr_ && !--*counter_) {
            delete ptr_;
            ptr_ = 0;
            delete counter_;
            counter_ = 0;
        }
    }
    Expression *ptr_;
    size_t *counter_;
};
