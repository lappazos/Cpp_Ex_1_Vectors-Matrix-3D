// Created by liorP
//

#include "Matrix3D.h"

#define INDEX_ERROR "Index out of bounds"
#define ZERO_ERR "Division in Zero"

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Vector3D.
// --------------------------------------------------------------------------------------

// ------------------ Operators Overloading ------------------------

/**
* + operator overload
* @param matrix2 matrix to be added with this matrix
* @return new matrix which is the addition of these two matrix.
*/
Matrix3D Matrix3D::operator+(const Matrix3D &matrix2) const
{
    auto ans = Matrix3D(*this);
    ans += matrix2;
    return ans;
}

/**
* - operator overload
* @param matrix2 matrix to be deducted from this matrix
* @return new matrix which is the deduction of these two matrix.
*/
Matrix3D Matrix3D::operator-(const Matrix3D &matrix2) const
{
    Matrix3D temp = matrix2;
    temp *= (- 1);
    return *this + temp;
}

/**
* += operator overload
* @param other matrix to be added
*/
void Matrix3D::operator+=(const Matrix3D &other)
{
    this->_line1 += other._line1;
    this->_line2 += other._line2;
    this->_line3 += other._line3;
}

/**
* -= operator overload
* @param other other matrix to be deducted from
*/
void Matrix3D::operator-=(const Matrix3D &other)
{
    Matrix3D temp = other;
    temp *= (- 1);
    *this += temp;
}

/**
* * operator overload
* @param vector to multiply with
* @return result vector
*/
Vector3D Matrix3D::operator*(const Vector3D &vector) const
{
    //3 dot products
    auto ans = Vector3D((this->_line1) * vector, (this->_line2) * vector, (this->_line3) * vector);
    return ans;
}

/**
* * operator overload
* @param other matrix to multiply with
* @return result Matrix3D
*/
Matrix3D Matrix3D::operator*(const Matrix3D &other) const
{
    auto ans = Matrix3D(*this);
    ans *= other;
    return ans;
}

/**
* *= operator overload
* @param other matrix to multiply with
*/
void Matrix3D::operator*=(const Matrix3D &other)
{
    //matrix multiplication algorithm
    Vector3D old_col1 = other.column(0);
    Vector3D old_col2 = other.column(1);
    Vector3D old_col3 = other.column(2);
    Vector3D col1 = *this * old_col1;
    Vector3D col2 = *this * old_col2;
    Vector3D col3 = *this * old_col3;
    this->_line1 = Vector3D(col1[0], col2[0], col3[0]);
    this->_line2 = Vector3D(col1[1], col2[1], col3[1]);
    this->_line3 = Vector3D(col1[2], col2[2], col3[2]);

}

/**
* *= operator overload
* @param scalar to multiply with - each of the elements with that that scalar
*/
void Matrix3D::operator*=(const double scalar)
{
    this->_line1 *= scalar;
    this->_line2 *= scalar;
    this->_line3 *= scalar;

}

/**
* /= operator overload
* @param scalar to divide with - each of the elements with that that scalar
*/
void Matrix3D::operator/=(const double scalar)
{
    if (scalar == 0)
    {
        cerr << ZERO_ERR << endl;
        return;
    }
    *this *= (1 / scalar);

}

/**
*[] operator overload
* @param i index of vector to approach to
* @return line1, line2 or line3 of the matrix according to index
*/
Vector3D &Matrix3D::operator[](const int i)
{
    if (i == 0)
    {
        return this->_line1;
    } else if (i == 1)
    {
        return this->_line2;
    } else if (i == 2)
    {
        return this->_line3;
    }
    cerr << INDEX_ERROR << endl;
    //error
    return this->_line1;
}

/**
*[] const operator overload
* @param i index of vector to approach to
* @return line1, line2 or line3 of the matrix according to index
*/
Vector3D Matrix3D::operator[](const int i) const
{
    if (i == 0)
    {
        return this->_line1;
    } else if (i == 1)
    {
        return this->_line2;
    } else if (i == 2)
    {
        return this->_line3;
    }
    cerr << INDEX_ERROR << endl;
    //error
    return this->_line1;
}

/**
* = operator overload
* @param matrix to copy
* @return refrence to copied matrix
*/
Matrix3D &Matrix3D::operator=(const Matrix3D other)
{
    this->_line1 = other._line3;
    this->_line2 = other._line2;
    this->_line3 = other._line3;
    return *this;
}

// ------------------ Other methods ------------------------

/**
* returns the i row of the matrix
* @param index of row to return
* @return Vector3D
*/
Vector3D Matrix3D::row(const short index) const
{
    if (index == 0)
    {
        return this->_line1;
    }
    else if (index == 1)
    {
        return this->_line2;
    }
    else if (index == 2)
    {
        return this->_line3;
    }
    cerr << INDEX_ERROR << endl;
    //error
    return this->_line1;
}

/**
* returns the i column of the matrix
* @param index of column to return
* @return Vector3D
*/
Vector3D Matrix3D::column(const short index) const
{
    if (index == 0)
    {
        return Vector3D(this->_line1[0], this->_line2[0], this->_line3[0]);
    }
    else if (index == 1)
    {
        return Vector3D(this->_line1[1], this->_line2[1], this->_line3[1]);
    }
    else if (index == 2)
    {
        return Vector3D(this->_line1[2], this->_line2[2], this->_line3[2]);
    }
    cerr << INDEX_ERROR << endl;
    //error
    return this->_line1;
}

/**
* gives the trace of the matrix
* @return trace as double
*/
double Matrix3D::trace() const
{
    //trace algorithm
    return _line1[0] + _line2[1] + _line3[2];
}

/**
* gives the determinant of the matrix
* @return determinant as double
*/
double Matrix3D::determinant() const
{
    //determinant algorithm
    return _line1[0] * (_line2[1] * _line3[2] - _line3[1] * _line2[2])
           - _line2[0] * (_line1[1] * _line3[2] - _line3[1] * _line1[2])
           + _line3[0] * (_line1[1] * _line2[2] - _line2[1] * _line1[2]);
}

// ------------------ Friend methods ------------------------

/**
* << operator overload, to send data of the matrix to out-stream.
* @param os out-stream
* @param matrix to print
* @return out stream with matrix
*/
ostream &operator<<(ostream &os, const Matrix3D &matrix)
{
    os << matrix._line1 << endl;
    os << matrix._line2 << endl;
    os << matrix._line3;
    return os;
}

/**
* >> operator overload, to receive data of matrix from in stream.
* @param is in-stream
* @param matrix to receive data into
* @return in stream
*/
istream &operator>>(istream &is, Matrix3D &matrix)
{
    is >> matrix._line1;
    is >> matrix._line2;
    is >> matrix._line3;
    return is;
}
