#include "vector.hh"

Vector::Vector(const Vector& v)
{
    this->data = std::make_unique<value[]>(v.size());
    this->_size = v.size();

    for (size_t i = 0; i != v.size(); ++i)
    {
        this->data[i] = v.data[i];
    }
}

Vector& Vector::operator=(const Vector& v)
{
    this->data = std::make_unique<value[]>(v.size());
    this->_size = v.size();

    for (size_t i = 0; i != v.size(); ++i)
    {
        this->data[i] = v.data[i];
    }
    return *this;
}

Vector::Vector(size_t N)
{
    this->data = std::make_unique<value[]>(N);
    this->_size = N;

    for (size_t i = 0; i != N; ++i)
    {
        this->data[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> l)
{
    this->_size = l.size();
    this->data = std::make_unique<value[]>(this->_size);
    size_t index = 0;
    std::initializer_list<value>::iterator iterator;
    for (iterator = l.begin(); iterator != l.end(); iterator++)
    {
        this->data[index] = *iterator;
        index++;
    } 
}

Vector Vector::operator+(const Vector& vec) const
{
    this->checkWrongSize(vec);
    Vector v = Vector(this->_size);
    for (size_t i = 0; i < this->_size; i++)
    {
        v.data[i] = this->data[i] + vec[i];
    }
    return v;
}

Vector Vector::operator+(value v) const
{
    Vector vec = Vector{};
    for (size_t i = 0; i < this->_size; i++)
    {
        vec.data[i] = this->data[i] + v;
    }
    return vec;
}

std::ostream& operator<<(std::ostream& out, const Vector& vec)
{
    out << "{";
    for (size_t i = 0; i < vec.size(); i++)
    {
        out << vec[i];
        out << (i == vec.size() - 1 ? "" : ",");
    }
    return out << "}";
}

size_t Vector::size() const
{
    return this->_size;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    this->checkWrongSize(rhs);
    for (size_t i = 0; i < this->_size; ++i)
    {
        this->data[i] += rhs[i];   
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    this->checkWrongSize(rhs);
    for (size_t i = 0; i < this->_size; ++i)
    {
        this->data[i] -= rhs[i];   
    }
    return *this;
}

Vector Vector::operator*(value val) const
{
    for (size_t i = 0; i < this->_size; ++i)
    {
        this->data[i] *= val;   
    }
    return *this;
}

value Vector::operator*(const Vector& rhs) const
{
    this->checkWrongSize(rhs);
    value res = 0;
    for (size_t i = 0; i < this->_size; ++i)
    {
        res += this->data[i] * rhs[i];   
    }
    return res;
}

value& Vector::operator[](size_t index)
{
    return this->data[index];
}

value Vector::operator[](size_t index) const
{
    return this->data[index];
}

Vector& Vector::operator*=(value val)
{
    for (size_t i = 0; i < this->_size; ++i)
    {
        data[i] *= val;
    }
    return *this;
}

Vector& Vector::operator+=(value val)
{
    for (size_t i = 0; i < this->_size; ++i)
    {
        this->data[i] += val;
    }
    return *this;
}

Vector operator*(const value &s, const Vector &v)
{
    Vector vec = Vector(v.size());
    for (size_t i = 0; i < v.size(); ++i)
    {
        vec[i] = v[i] * s;
    }
    return vec;
}

Vector operator+(const value &s, const Vector &v)
{
    Vector vec = Vector(v.size());
    for (size_t i = 0; i < v.size(); ++i)
    {
        vec[i] = v[i] + s;
    }
    return vec;
}

void Vector::checkWrongSize(const Vector& rhs) const
{
    if (this->size() != rhs.size())
        throw std::runtime_error("Incompatible size");
}