#pragma once 

#include <iostream>
#include <cmath>
using namespace std;

namespace nebula {
    namespace maths {
        class vect3
        {
        public:
            float x, y, z;

            //Constructors
            vect3(): x(0.0f), y(0.0f), z(0.0f) {}
            vect3(float x, float y, float z): x(x), y(y), z(z) {}

            //Vector operations
            vect3 operator+(const vect3& other) const {return vect3(x + other.x, y + other.y, z + other.z); }
            vect3 operator-(const vect3& other) const {return vect3(x - other.x, y - other.y, z - other.z); }
            vect3 operator*(float scalar) const {return vect3(x * scalar, y * scalar, z * scalar); }
            vect3 operator/(float scalar) const {return vect3(x / scalar, y / scalar, z / scalar); }

            vect3& operator+=(const vect3& other)
            {
                x += other.x;
                y += other.y;
                z += other.z;
                return *this;
            }
            vect3& operator-=(const vect3& other)
            {
                x -= other.x;
                y -= other.y;
                z -= other.z;
                return *this;
            }
            vect3& operator*=(float scalar)
            {
                x *= scalar;
                y *= scalar;
                z *= scalar;
                return *this;
            }
            vect3& operator/=(float scalar)
            {
                x /= scalar;
                y /= scalar;
                z /= scalar;
                return *this;
            }

            bool operator==(const vect3& other) const
            {
                return (x == other.x && y == other.y && z == other.z);
            }

            bool operator!=(const vect3& other) const
            {
                return (x != other.x && y != other.y && z != other.z);
            }    
            //Dot product
            float dot(const vect3& other) const {return x * other.x + y * other.y + z * other.z;}
            vect3 cross(const vect3& other)
            {
                return vect3
                (
                    y * other.z - z * other.y,
                    z * other.x - x * other.z,
                    x * other.y - y * other.x
                );
            }
            float magnitude() const {return std::sqrt(x * x + y * y + z * z);}
            vect3 normalize() const
            {
                float mag = magnitude();
                return mag > 0 ? *this / mag: vect3();
            }

            friend std::ostream& operator<<(std::ostream& os, const vect3& v)
            {
                os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
                return os;
            }
        };
    }
}