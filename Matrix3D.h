// Created by liorP.
//

#ifndef EX1_MATRIX3D_H
#define EX1_MATRIX3D_H

#include "Vector3D.h"

/**
 * A Matrix class.
 * This class represents a Matrix 3*3.
 */
class Matrix3D
{
public:
    /**
     * A Constructor.
     * inits with 3 vectors
     * @param vec1 Vector3D
     * @param vec2 Vector3D
     * @param vec3 Vector3D
     */
    Matrix3D(Vector3D vec1, Vector3D vec2, Vector3D vec3) : _line1(Vector3D(vec1)),
                                                            _line2(Vector3D(vec2)), _line3(Vector3D(vec3)) {}

    /**
     * A default Constructor - zero matrix.
     */
    Matrix3D() : Matrix3D(Vector3D(), Vector3D(), Vector3D()) {}

    /**
     * A Constructor - scalar matrix.
     * @param scalar double as scalar
     */
    explicit Matrix3D(double scalar) : Matrix3D(Vector3D(scalar, 0, 0), Vector3D(0, scalar, 0),
                                                Vector3D(0, 0, scalar)) {}

    /**
     * A Copy Constructor.
     * @param matrix to copy from
     */
    Matrix3D(const Matrix3D &matrix) = default;

    /**
     * A Constructor - 9 doubles.
     * @param a double [0][0]
     * @param b double [0][1]
     * @param c double [0][2]
     * @param d double [1][0]
     * @param e double [1][1]
     * @param f double [1][2]
     * @param g double [2][0]
     * @param h double [2][1]
     * @param i double [2][2]
     */
    Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h, double i) :
            _line1(Vector3D(a, b, c)), _line2(Vector3D(d, e, f)), _line3(Vector3D(g, h, i)) {}

    /**
     * A constructor - array with 9 doubles
     * @param arr double[9]
     */
    explicit Matrix3D(const double arr[9]) : Matrix3D(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7],
                                                      arr[8]) {}

    /**
     * A Constructor - 2 dimensional array 3*3
     * @param arr double[3][3]
     */
    explicit Matrix3D(const double arr[3][3]) : Matrix3D(Vector3D(arr[0]), Vector3D(arr[1]), Vector3D(arr[2])) {}

    /**
     * + operator overload
     * @param matrix2 matrix to be added with this matrix
     * @return new matrix which is the addition of these two matrix.
     */
    Matrix3D operator+(const Matrix3D &matrix2) const;

    /**
     *- operator overload
     * @param matrix2 matrix to be deducted from this matrix
     * @return new matrix which is the deduction of these two matrix.
     */
    Matrix3D operator-(const Matrix3D &matrix2) const;

    /**
     * += operator overload
     * @param other matrix to be added
     */
    void operator+=(const Matrix3D &other);

    /**
     * -= operator overload
     * @param other other matrix to be deducted from
     */
    void operator-=(const Matrix3D &other);

    /**
     * * operator overload
     * @param vector to multiply with
     * @return result vector
     */
    Vector3D operator*(const Vector3D &vector) const;

    /**
     * * operator overload
     * @param other matrix to multiply with
     * @return result Matrix3D
     */
    Matrix3D operator*(const Matrix3D &other) const;

    /**
     * *= operator overload
     * @param other matrix to multiply with
     */
    void operator*=(const Matrix3D &other);

    /**
     * *= operator overload
     * @param scalar to multiply with - each of the elements with that that scalar
     */
    void operator*=(double scalar);

    /**
     * /= operator overload
     * @param scalar to divide with - each of the elements with that that scalar
     */
    void operator/=(double scalar);

    /**
     *[] operator overload
     * @param i index of vector to approach to
     * @return line1, line2 or line3 of the matrix according to index
     */
    Vector3D &operator[](int i);

    /**
     *[] const operator overload
     * @param i index of vector to approach to
     * @return line1, line2 or line3 of the matrix according to index
     */
    Vector3D operator[](int i) const;

    /**
     * = operator overload
     * @param matrix to copy
     * @return refrence to copied matrix
     */
    Matrix3D &operator=(Matrix3D other);

    /**
     * returns the i row of the matrix
     * @param index of row to return
     * @return Vector3D
     */
    Vector3D row(short index) const;

    /**
     * returns the i column of the matrix
     * @param index of column to return
     * @return Vector3D
     */
    Vector3D column(short index) const;

    /**
     * gives the trace of the matrix
     * @return trace as double
     */
    double trace() const;

    /**
     * gives the determinant of the matrix
     * @return determinant as double
     */
    double determinant() const;

    /**
     * << operator overload, to send data of the matrix to out-stream.
     * @param os out-stream
     * @param matrix to print
     * @return out stream with matrix
     */
    friend ostream &operator<<(ostream &os, const Matrix3D &matrix);

    /**
     * >> operator overload, to receive data of matrix from in stream.
     * @param is in-stream
     * @param matrix to receive data into
     * @return in stream
     */
    friend istream &operator>>(istream &is, Matrix3D &matrix);

private:
    Vector3D _line1; /**< the first row. */
    Vector3D _line2; /**< the second row. */
    Vector3D _line3; /**< the third row. */

};

#endif //EX1_MATRIX3D_H
