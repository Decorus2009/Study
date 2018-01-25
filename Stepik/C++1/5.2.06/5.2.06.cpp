struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;

    int numerator() const {
        return numerator_;
    }

    int denominator() const {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);


bool operator==(Rational lhs, Rational rhs) {
    return lhs.numerator() == rhs.numerator() && lhs.denominator() == rhs.denominator();
}

bool operator!=(Rational lhs, Rational rhs) {
    return !(lhs == rhs);
}

bool operator<(Rational lhs, Rational rhs) {
    return (lhs - rhs).numerator() < 0;
}

bool operator>(Rational lhs, Rational rhs) {
    return rhs < lhs;
}

bool operator<=(Rational lhs, Rational rhs) {
    return !(lhs > rhs);
}

bool operator>=(Rational lhs, Rational rhs) {
    return !(lhs < rhs);
}
