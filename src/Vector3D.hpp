#pragma once
#include <ostream>

class Vector3D {

    public :
        Vector3D();
        Vector3D(double e0, double e1, double e2);

        double x() const;
        double y() const;
        double z() const;

        Vector3D operator-() const;
        double operator[](int i) const;
        double& operator[](int i); 

        Vector3D& operator+=(const Vector3D &v);
        

        Vector3D& operator*=(const Vector3D &v);

        Vector3D& operator/=(const double t);
        double LengthSquared() const;
        double Length() const;

        bool NearZero() const; 
        
        static Vector3D Random();
        static Vector3D Random(double min, double max);

    private:
        double e_[3];

};

// utility functions
std::ostream& operator<<(std::ostream &out, const Vector3D &v);
Vector3D operator+(const Vector3D &u, const Vector3D &v);
Vector3D operator-(const Vector3D &u, const Vector3D &v);
Vector3D operator*(const Vector3D &u, const Vector3D &v);
Vector3D operator*(double t, const Vector3D &v);
Vector3D operator*(const Vector3D &v, double t);
Vector3D operator/(Vector3D v, double t);

double Dot(const Vector3D &u, const Vector3D &v);
Vector3D Cross(const Vector3D &u, const Vector3D &v);
Vector3D UnitVector(Vector3D v);
Vector3D Reflect(const Vector3D& v, const Vector3D& n);

Vector3D RandomInUnitSphere();
Vector3D RandomUnitVector();
Vector3D RandomInHemisphere(const Vector3D& normal); 

        
using Point3D = Vector3D;
using Color = Vector3D;
