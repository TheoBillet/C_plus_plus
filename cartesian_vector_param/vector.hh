#pragma once

#include <ostream>
#include <initializer_list>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector(std::initializer_list<value> param);
    size_t getSize() const;
    value getDatas(size_t index) const;
     value& operator[](size_t idx);
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& rhs);
    // More to go
    Vector operator+(const Vector& vec);
    Vector& operator-=(const Vector& rhs);
    Vector& operator*(value val);
    value operator*(const Vector& rhs);
    Vector& operator*=(value val);
    Vector& operator+=(value val);

private:
// Private Member functions here

// Member variables are ALWAYS private, and they go here
    value datas[NDIM];
    size_t size;
};

// Nonmember function operators go here
std::ostream& operator<<(std::ostream& out, const Vector& vec);