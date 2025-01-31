#pragma once

#include <iostream>
#include <cmath>
using namespace std;

namespace nebula {
    namespace maths {
        class vect2
        {
        public: 
            float x, y;

            //Constructors
            vect2(): x(0.0f), y(0.0f) {}
            vect2(float x, float y): x(x), y(y) {}

            //Vector operations
            vect2 operator+(const vect2& other) const {return vect2(x + other.x, y + other.y);}
            vect2 operator-(const vect2& other) const {return vect2(x - other.x, y - other.y);}
            vect2 operator*(float scalar) const {return vect2(x * scalar, y * scalar);}
            vect2 operator/(float scalar) const {return vect2(x / scalar, y / scalar);}

            vect2& operator+=(const vect2& other)
            {
                x += other.x;
                y += other.y;
                return *this;
            }
            vect2& operator-=(const vect2& other)
            {
                x -= other.x;
                y -= other.y;
                return *this;
            }

            vect2& operator*=(float scalar)
            {
                x *= scalar;
                y *= scalar;
                return *this;
            }

            vect2& operator/=(float scalar)
            {
                x /= scalar;
                y /= scalar;
                return *this;
            }

            bool operator==(const vect2& other) const
            {
                return (x == other.x && y == other.y);
            }

            bool operator!=(const vect2& other) const
            {
                return (x != other.x && y != other.y);
            }    

            //Dot product
            float dot(const vect2& other) const {return x * other.x + y * other.y;}

            //Magnitude and normalization
            float magnitude() const {return std::sqrt(x * x + y * y); }
            vect2 normalize() const 
            {
                float mag = magnitude();
                return mag > 0 ? *this / mag : vect2();
            }

            //Display the vector
            friend std::ostream& operator<<(std::ostream& os, const vect2& v)
            {
                os << "(" << v.x << ", " << v.y << ")";
                return os;
            }
        };
    }
}