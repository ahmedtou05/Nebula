#pragma once
#include <cmath>
#include <iostream>

namespace nebula {
    namespace maths {
        class vect4 {
        public:
            float x, y, z, w;

            // Constructors
            vect4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
            vect4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

            // vect operations
            vect4 operator+(const vect4& other) const { return vect4(x + other.x, y + other.y, z + other.z, w + other.w); }
            vect4 operator-(const vect4& other) const { return vect4(x - other.x, y - other.y, z - other.z, w - other.w); }
            vect4 operator*(float scalar) const { return vect4(x * scalar, y * scalar, z * scalar, w * scalar); }
            vect4 operator/(float scalar) const { return vect4(x / scalar, y / scalar, z / scalar, w / scalar); }

            vect4& operator+=(const vect4& other)
            {
                x += other.x;
                y += other.y;
                z += other.z;
                w += other.w;
                return *this;
            }
            vect4& operator-=(const vect4& other)
            {
                x -= other.x;
                y -= other.y;
                z -= other.z;
                w -= other.w;
                return *this;
            }

            vect4& operator*=(float scalar)
            {
                x *= scalar;
                y *= scalar;
                z *= scalar;
                w *= scalar;
                return *this;
            }

            vect4& operator/=(float scalar)
            {
                x /= scalar;
                y /= scalar;
                z /= scalar;
                w /= scalar;
                return *this;
            }

            bool operator==(const vect4& other) const
            {
                return (x == other.x && y == other.y && z == other.z && w == other.w);
            }

            bool operator!=(const vect4& other) const
            {
                return (x != other.x && y != other.y && z != other.z && w != other.w);
            }    
            // Dot product
            float dot(const vect4& other) const { return x * other.x + y * other.y + z * other.z + w * other.w; }

            // Magnitude and normalization
            float magnitude() const { return std::sqrt(x * x + y * y + z * z + w * w); }
            vect4 normalize() const {
                float mag = magnitude();
                return mag > 0 ? *this / mag : vect4();
            }

            // Display vect
            friend std::ostream& operator<<(std::ostream& os, const vect4& v) {
                os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
                return os;
            }
        };
    }
}