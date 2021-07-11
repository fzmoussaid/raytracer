#include <cmath>
#include <ostream>
#include "Vector3D.hpp"
#include "Utils.hpp"

Vector3D::Vector3D(): e_{0,0,0}{}
Vector3D::Vector3D(double e0, double e1, double e2): e_{e0,e1,e2} {}

double Vector3D::x() const {return e_[0];}
double Vector3D::y() const {return e_[1];}
double Vector3D::z() const {return e_[2];}

Vector3D Vector3D::operator-() const {return Vector3D(e_[0], e_[1], e_[2]);}
double Vector3D::operator[](int i) const {return e_[i];}
double& Vector3D::operator[](int i) {return e_[i];} 

Vector3D& Vector3D::operator+=(const Vector3D &v) {
    e_[0] += v.e_[0];
    e_[1] += v.e_[1];
    e_[2] += v.e_[2];
    return *this;
}
        
Vector3D& Vector3D::operator*=(const Vector3D &v) {
    e_[0] *= v.e_[0];
    e_[1] *= v.e_[1];
    e_[2] *= v.e_[2];
    return *this;
}

Vector3D& Vector3D::operator/=(const double t) {
    e_[0] *= 1/t;
    e_[1] *= 1/t;
    e_[2] *= 1/t;
    return *this;
}

double Vector3D::LengthSquared() const {
    return e_[0]*e_[0] + e_[1]*e_[1] + e_[2]*e_[2];
    }

double Vector3D::Length() const {
    return sqrt(LengthSquared());
}
     
Vector3D Vector3D::Random() {
    return Vector3D(RandomDouble(), RandomDouble(), RandomDouble());
}

Vector3D Vector3D::Random(double min, double max) {
    return Vector3D(RandomDouble(min,max), RandomDouble(min,max), RandomDouble(min,max));
}

std::ostream& operator<<(std::ostream &out, const Vector3D &v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

Vector3D operator+(const Vector3D &u, const Vector3D &v) {
    return Vector3D(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

 Vector3D operator-(const Vector3D &u, const Vector3D &v) {
    return Vector3D(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

Vector3D operator*(const Vector3D &u, const Vector3D &v) {
    return Vector3D(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

Vector3D operator*(double t, const Vector3D &v) {
    return Vector3D(t*v.x(), t*v.y(), t*v.z());
}

Vector3D operator*(const Vector3D &v, double t) {
    return t * v;
}

Vector3D operator/(Vector3D v, double t) {
    return (1/t) * v;
}

double Dot(const Vector3D &u, const Vector3D &v) {
    return u.x() * v.x()
         + u.y() * v.y()
         + u.z() * v.z();
}

Vector3D Cross(const Vector3D &u, const Vector3D &v) {
    return Vector3D(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

Vector3D UnitVector(Vector3D v) {
    return v / v.Length();
}

Vector3D RandomInUnitSphere() {
   while (true) {
        auto p = Vector3D::Random(-1,1);
        if (p.LengthSquared() >= 1) continue;
        return p;
    }
}

Vector3D RandomUnitVector() {
    return UnitVector(RandomInUnitSphere());
}

Vector3D RandomInHemisphere(const Vector3D& normal){
    Vector3D in_unit_sphere = RandomInUnitSphere();
    if (Dot(in_unit_sphere, normal) > 0.0)
        return in_unit_sphere;
    else
        return -in_unit_sphere;   

}



