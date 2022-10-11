#include "vector.hh"

Vector::Vector()
{
    this->size = NDIM;
    for (size_t i = 0; i < NDIM; i++)
    {
        this->datas[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> param)
{
    this->size = param.size();
    size_t index = 0;
    std::initializer_list<value>::iterator iterator;
    for (iterator = param.begin(); iterator != param.end(); iterator++)
    {
        this->datas[index] = *iterator;
        index++;
    } 
}

Vector Vector::operator+(const Vector& vec)
{
    Vector v = Vector{};
    for (size_t i = 0; i < this->size; i++)
    {
        v.datas[i] = this->datas[i] + vec.getDatas(i);
    }
    return v;
}

std::ostream& operator<<(std::ostream& out, const Vector& vec)
{
    out << "{";
    for (size_t i = 0; i < vec.getSize(); i++)
    {
        out << vec.getDatas(i);
        out << (i == vec.getSize() - 1 ? "" : ",");
    }
    return out << "}";
}

size_t Vector::getSize() const
{
    return this->size;
}

value Vector::getDatas(size_t index) const
{
    return this->datas[index];
}

Vector& Vector::operator+=(const Vector& rhs)
{
    for (size_t i = 0; i < this->size; ++i)
    {
        this->datas[i] += rhs.getDatas(i);   
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    for (size_t i = 0; i < this->size; ++i)
    {
        this->datas[i] -= rhs.getDatas(i);   
    }
    return *this;
}

Vector& Vector::operator*(value val)
{
    for (size_t i = 0; i < this->size; ++i)
    {
        this->datas[i] *= val;   
    }
    return *this;
}

value Vector::operator*(const Vector& rhs)
{
    value res = 0;
    for (size_t i = 0; i < this->size; ++i)
    {
        res += this->datas[i] * rhs.getDatas(i);   
    }
    return res;
}

value& Vector::operator[](size_t index)
{
    return this->datas[index];
}

Vector& Vector::operator*=(value val)
{
    for (size_t i = 0; i < this->size; ++i)
    {
        datas[i] *= val;
    }
    return *this;
}

Vector& Vector::operator+=(value val)
{
    for (size_t i = 0; i < this->size; ++i)
    {
        this->datas[i] += val;
    }
    return *this;
}