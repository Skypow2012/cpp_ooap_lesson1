#include <iostream>

class Date
{
public:
    Date(int year = 0, int month = 0, int day = 0)
      : m_year (year), m_month (month), m_day (day)
    { }
    bool operator < (const Date&) const;
    bool operator > (const Date&) const;
    bool operator == (const Date&) const;
    void print() const;
private:
    int __comparable_value() const { return (m_year * 10000 + m_month * 100 + m_day); }
    int m_year;
    int m_month;
    int m_day;
};

inline bool
Date::operator < (const Date& r) const
{
    const int lvalue = this->__comparable_value();
    const int rvalue = r.__comparable_value();
    if (lvalue < rvalue)
        return true;
    return false;
}

inline bool
Date::operator > (const Date& r) const
{
    return (r < *this);
}

inline bool
Date::operator == (const Date& r) const
{
    return !(*this < r) && !(*this > r);
}

inline void
Date::print() const
{
    std::cout << m_year << "-" << m_month << "-" << m_day << std::endl;
}

int main()
{
    return 0;
}
