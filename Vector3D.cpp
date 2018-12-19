// Created by liorP.
//

#include <cmath>
#include <iostream>
#include "Vector3D.h"

using namespace std;

#define SPACE " "
#define INDEX_ERROR "Index out of bounds"
#define ZERO_ERR "Division in Zero"

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Vector3D.
// --------------------------------------------------------------------------------------

// ------------------ Operators Overloading ------------------------

/**
* + operator overload
* @param vector2 a vector to be added
* @return result of 2 vectors addition- Vector
*/
Vector3D Vector3D::operator+(const Vector3D &vector2) const
{
    auto ans = Vector3D(*this);
    ans += vector2;
    return ans;
}

/**
* - operator overload
* @param vector2 a vector to be deducted
* @return result of 2 vectors deduction- Vector
*/
Vector3D Vector3D::operator-(const Vector3D &vector2) const
{
    return *this + (vector2 * (- 1));
}

/**
* += operator overload. changes the original vector
* @param other vector to be added to the current
*/
void Vector3D::operator+=(const Vector3D &other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
}

/**
* -= operator overload. changes the original vector
* @param other vector to be deducted from the current
*/
void Vector3D::operator-=(const Vector3D &other)
{
    *this += (- 1) * other;
}

/**
* - operator overload.
* doubles the vector by -1.
* @return Vector3D
*/
Vector3D Vector3D::operator-() const
{
    // just as multi by scalar -1.
    return *this * (- 1);
}

/**
* * operator overload
* @param scalar double to increase the vector by
* @return Vector3D
*/
Vector3D Vector3D::operator*(const double scalar) const
{
    // multi each coordinate by the scalar
    auto ans = Vector3D(this->_x * scalar, this->_y * scalar, this->_z * scalar);
    return ans;
}

/**
* / operator overload
* @param scalar double to decrease the vector by
* @return Vector3D
*/
Vector3D Vector3D::operator/(const double scalar) const
{
    if (scalar == 0)
    {
        cerr << ZERO_ERR << endl;
    }
    return *this * (1 / scalar);
}

/**
* *= operator overload
* changes the original vector to be multiplied by a certain scalar.
* @param scalar double to increase the vector by
*/
void Vector3D::operator*=(const double scalar)
{
    this->_x *= scalar;
    this->_y *= scalar;
    this->_z *= scalar;

}

/**
* /= operator overload
* changes the original vector to be divided by a certain scalar.
* @param scalar double to divide the vector by
*/
void Vector3D::operator/=(const double scalar)
{
    if (scalar == 0)
    {
        cerr << ZERO_ERR << endl;
        return;
    }
    *this *= (1 / scalar);
}

/**
* | operator overload
* gives the distance between 2 vectors
* @param vector2 vector to calculate dist from
* @return distance as double
*/
double Vector3D::operator|(const Vector3D &vector2) const
{
    Vector3D temp = *this - vector2;
    //the way to calculate distance between vectors
    return sqrt(pow(temp._x, 2) + pow(temp._y, 2) + pow(temp._z, 2));
}

/**
* * operator overload as dot product of 2 vectors
* @param vector2 to calculate dot product to
* @return dot product as double
*/
double Vector3D::operator*(const Vector3D &vector2) const
{
    //dot product of 2 vectors
    return this->_x * vector2._x + this->_y * vector2._y + this->_z * vector2._z;
}

/**
* ^ operator overload. calculate angle between vectors.
* @param vector2 calculate angle to
* @return angle in radians as double
*/
double Vector3D::operator^(const Vector3D &vector2) const
{
    //angle formula
    return acos(*this * vector2 / (this->norm() * vector2.norm()));
}

/**
* = operator overload.
* @param other vector to copy from
* @return reference to the new vector
*/
Vector3D &Vector3D::operator=(const Vector3D other)
{
    this->_x = other._x;
    this->_y = other._y;
    this->_z = other._z;
    return *this;
}

/**
*[] operator overload
* @param i index of vector to approach to
* @return x, y or z of the vector according to index
*/
double &Vector3D::operator[](const int i)
{
    if (i == 0)
    {
        return this->_x;
    } else if (i == 1)
    {
        return this->_y;
    } else if (i == 2)
    {
        return this->_z;
    }
    cerr << INDEX_ERROR << endl;
    //error
    return this->_x;
}

/**
*[] const operator overload
* @param i index of coordinate to approach to
* @return x, y or z of the vector according to index
*/
double Vector3D::operator[](const int i) const
{
    if (i == 0)
    {
        return this->_x;
    } else if (i == 1)
    {
        return this->_y;
    } else if (i == 2)
    {
        return this->_z;
    }
    cerr << INDEX_ERROR << endl;
    //error
    return this->_x;
}

/**
* += operator over load between vector & double.
* add the double to each of the coordinates
* @param num double to add
*/
void Vector3D::operator+=(double num)
{
    this->_x += num;
    this->_y += num;
    this->_z += num;
}

/**
* -= operator over load between vector & double.
* deduct the double from each of the coordinates
* @param num double to deduct
*/
void Vector3D::operator-=(double num)
{
    *this += (- num);
}

// ------------------ Other methods ------------------------

/**
* returns the norm of the vector
* @return norm as double
*/
double Vector3D::norm() const
{
    //norm is distance from zero
    Vector3D _zero = Vector3D();
    return _zero | *this;
}

/**
*calculates the distance between this vector and another
* @param other vector to calculate dist from
* @return distance as double
*/
double Vector3D::dist(const Vector3D &other) const
{
    //same as the operator
    return *this | other;
}

// ------------------ Friend methods ------------------------

/**
* * operator overload - multiply vector by scalar
* @param scalar to multiply by
* @param other vector to multiply
* @return the result vector
*/
Vector3D operator*(double scalar, const Vector3D &other)
{
    return other * scalar;
}

/**
* << operator overload, to send data of the vector to out-stream.
* @param os out-stream
* @param vector vector to print
* @return out stream with vector
*/
ostream &operator<<(ostream &os, const Vector3D &vector)
{
    os << vector._x << SPACE;
    os << vector._y << SPACE;
    os << vector._z;
    return os;
}

/**
* >> operator overload, to receive data of vector from in stream.
* @param is in-stream
* @param vector vector to receive data into
* @return in stream
*/
istream &operator>>(istream &is, Vector3D &vector)
{
    is >> vector._x;
    is >> vector._y;
    is >> vector._z;
    return is;
}
