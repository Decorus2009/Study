struct Expression {
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

struct Number : Expression {
    Number(double value) : value(value) {}

    virtual double evaluate() const override {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression {
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right) {}

    virtual double evaluate() const override {
        switch (op) {
            case '+':
                return left->evaluate() + right->evaluate();
            case '-':
                return left->evaluate() - right->evaluate();
            case '*':
                return left->evaluate() * right->evaluate();
            case '/':
                return left->evaluate() / right->evaluate();
            default:
                break;
        }
    }

    virtual ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};
