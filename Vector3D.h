// Created by liorP.
//

#ifndef EX1_VECTOR3D_H
#define EX1_VECTOR3D_H

#include <iostream>

using namespace std;

/**
 * A Vector class.
 * This class represents a vector with 3 coordinates.
 */
class Vector3D
{
public:
    /**
     * A constructor.
     * inits with 3 doubles.
     * @param x double
     * @param y double
     * @param z double
     */
    Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

    /**
     * A default constructor.
     * inits the zero vector
     */
    Vector3D() : Vector3D(0, 0, 0) {}

    /**
     * A constructor.
     * @param arr array of 3 doubles for the vector
     */
    explicit Vector3D(const double arr[3]) : Vector3D(arr[0], arr[1], arr[2]) {}

    /**
     * A copy constructor.
     * @param vector
     */
    Vector3D(const Vector3D &vector) = default;

    /**
     * + operator overload
     * @param vector2 a vector to be added
     * @return result of 2 vectors addition- Vector
     */
    Vector3D operator+(const Vector3D &vector2) const;

    /**
     * - operator overload
     * @param vector2 a vector to be deducted
     * @return result of 2 vectors deduction- Vector
     */
    Vector3D operator-(const Vector3D &vector2) const;

    /**
     * += operator overload. changes the original vector
     * @param other vector to be added to the current
     */
    void operator+=(const Vector3D &other);

    /**
     * -= operator overload. changes the original vector
     * @param other vector to be deducted from the current
     */
    void operator-=(const Vector3D &other);

    /**
     * += operator over load between vector & double.
     * add the double to each of the coordinates
     * @param num double to add
     */
    void operator+=(double num);

    /**
     * -= operator over load between vector & double.
     * deduct the double from each of the coordinates
     * @param num double to deduct
     */
    void operator-=(double num);

    /**
     * - operator overload.
     * doubles the vector by -1.
     * @return Vector3D
     */
    Vector3D operator-() const;

    /**
     * * operator overload
     * @param scalar double to increase the vector by
     * @return Vector3D
     */
    Vector3D operator*(double scalar) const;

    /**
     * / operator overload
     * @param scalar double to decrease the vector by
     * @return Vector3D
     */
    Vector3D operator/(double scalar) const;

    /**
     * *= operator overload
     * changes the original vector to be multiplied by a certain scalar.
     * @param scalar double to increase the vector by
     */
    void operator*=(double scalar);

    /**
     * /= operator overload
     * changes the original vector to be divided by a certain scalar.
     * @param scalar double to divide the vector by
     */
    void operator/=(double scalar);

    /**
     *[] operator overload
     * @param i index of vector to approach to
     * @return x, y or z of the vector according to index
     */
    double &operator[](int i);

    /**
     *[] const operator overload
     * @param i index of coordinate to approach to
     * @return x, y or z of the vector according to index
     */
    double operator[](int i) const;

    /**
     * | operator overload
     * gives the distance between 2 vectors
     * @param vector2 vector to calculate dist from
     * @return distance as double
     */
    double operator|(const Vector3D &vector2) const;

    /**
     * * operator overload as dot product of 2 vectors
     * @param vector2 to calculate dot product to
     * @return dot product as double
     */
    double operator*(const Vector3D &vector2) const;

    /**
     * ^ operator overload. calculate angle between vectors.
     * @param vector2 calculate angle to
     * @return angle in radians as double
     */
    double operator^(const Vector3D &vector2) const;

    /**
     * = operator overload.
     * @param other vector to copy from
     * @return reference to the new vector
     */
    Vector3D &operator=(Vector3D other);

    /**
     * returns the norm of the vector
     * @return norm as double
     */
    double norm() const;

    /**
     *calculates the distance between this vector and another
     * @param other vector to calculate dist from
     * @return distance as double
     */
    double dist(const Vector3D &other) const;

    /**
     * << operator overload, to send data of the vector to out-stream.
     * @param os out-stream
     * @param vector vector to print
     * @return out stream with vector
     */
    friend ostream &operator<<(ostream &os, const Vector3D &vector);

    /**
     * >> operator overload, to receive data of vector from in stream.
     * @param is in-stream
     * @param vector vector to receive data into
     * @return in stream
     */
    friend istream &operator>>(istream &is, Vector3D &vector);

    /**
     * * operator overload - multiply vector by scalar
     * @param scalar to multiply by
     * @param other vector to multiply
     * @return the result vector
     */
    friend Vector3D operator*(double scalar, const Vector3D &other);

private:
    double _x; /**< the x coordinate. */
    double _y; /**< the x coordinate. */
    double _z; /**< the x coordinate. */

};

#endif //EX1_VECTOR3D_H
