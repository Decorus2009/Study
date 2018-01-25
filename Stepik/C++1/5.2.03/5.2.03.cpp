struct Rational {
    Rational(int numerator = 0, int denominator = 1);

    Rational(Rational const &that) {
        numerator_ = that.numerator_;
        denominator_ = that.denominator_;
    }

    Rational &operator=(Rational const &that) {
        if (this != &that) {
            numerator_ = that.numerator_;
            denominator_ = that.denominator_;
        }
        return *this;
    }

    void add(Rational rational);

    void sub(Rational rational);

    void mul(Rational rational);

    void div(Rational rational);

    Rational operator+() const {
        return Rational(*this);
    }

    Rational operator-() const {
        return Rational(-numerator_, denominator_);
    }

    Rational &operator+=(Rational const &that) {
        this->add(that);
        return *this;
    }

    Rational &operator-=(Rational const &that) {
        this->sub(that);
        return *this;
    }

    Rational &operator*=(Rational const &that) {
        this->mul(that);
        return *this;
    }

    Rational &operator/=(Rational const &that) {
        this->div(that);
        return *this;
    }

    void neg();

    void inv();

    double to_double() const;

private:
    int numerator_;
    int denominator_;
};

Rational &operator+=(int number, Rational &rational) {
    return rational += Rational(number, 1);
}

Rational &operator-=(int number, Rational &rational) {
    return rational -= Rational(number, 1);
}

Rational &operator*=(int number, Rational &rational) {
    return rational *= Rational(number, 1);
}

Rational &operator/=(int number, Rational &rational) {
    return rational /= Rational(number, 1);
}
