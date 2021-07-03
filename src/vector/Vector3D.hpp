#pragma once

class Vector3D {

    public :
        Vector3D();
        Vector3D(double e0, double e1, double e2);

        double x();
        double y();
        double z();

        Vector3D operator-() const;
        double operator[](int i) const;
        double& operator[](int i); 

        Vector3D& operator+=(const Vector3D &v);
        

        Vector3D& operator*=(const Vector3D &v);

        Vector3D& operator/=(const double t):
        double LengthSquared() const;
        double Length() const;

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
Vector3D UnitVector(Vector3D v) ;

using Point3D = Vector3D;
using Color = Vector3D;
