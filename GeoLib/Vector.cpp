#include "Vector.h"

using namespace std;

// コンストラクタ
Vector::Vector() {
    x = 0.0;
    y = 0.0;
}

// コピーコンストラクタ
Vector::Vector(const Vector& v) {
    x = v.x;
    y = v.y;
}

// コンストラクタ(引数あり)
Vector::Vector(double nx, double ny) {
    x = nx;
    y = ny;
}

// x,yを設定する
void Vector::set(double nx, double ny) {
    x = nx;
    y = ny;
}

// 大きさを求める
double Vector::norm() const {
    return sqrt(x * x + y * y);
}

// 回転する
void Vector::rotate(double radian) {
    x = x * cos(radian) - y * sin(radian);
    x = x * sin(radian) + y * cos(radian);
}

// 内積を求める
double Vector::dot(const Vector& vec) const {
    return x * vec.x + y * vec.y;
}

// 外積を求める
double Vector::cross(const Vector& vec) const {
    return x * vec.y - y * vec.x;
}
// 余弦を返す
double Vector::getCos(const Vector& vec) const {
    double nor = norm() * vec.norm();
    if (nor == 0.0) {
        return 0.0;
    } else {
        return dot(vec) / nor;
    }
}

// 単位ベクトルを返す
Vector Vector::getUnit() const {
    Vector v;
    double mag = norm();
    if (mag == 0.0) {
        v.set(0.0, 0.0);
    } else {
        v.set(x / mag, y / mag);
    }
    return v;
}

// ベクトル1をベクトル2に正射影したベクトルを求める
Vector Vector::getProjection(const Vector& vec1, const Vector& vec2) {
    Vector vec(vec2.getUnit() * vec1.norm() * vec1.getCos(vec2));
    return vec;
}

void Vector::operator = (const Vector& vec) {
    x = vec.x;
    y = vec.y;
}

Vector Vector::operator + (const Vector& vec) const {
    Vector v(x + vec.x, y + vec.y);
    return v;
}

Vector Vector::operator - (const Vector& vec) const {
    Vector v(x - vec.x, y - vec.y);
    return v;
}

Vector Vector::operator * (const Vector& vec) const {
    Vector v(x * vec.x, y * vec.y);
    return v;
}

Vector Vector::operator * (double f) const {
    Vector v(x * f, y * f);
    return v;
}

Vector Vector::operator / (const Vector& vec) const {
    Vector v;
    if (vec.x == 0.0) {
        v.setX(0.0);
    } else {
        v.setX(x / vec.x);
    }
    
    if (vec.y == 0.0) {
        v.setY(0.0);
    } else {
        v.setY(y / vec.y);
    }
    return v;
}

Vector Vector::operator / (double f) const {
    Vector v;
    if (f == 0.0) {
        v.set(0.0, 0.0);
    } else {
        v.set(x / f, y / f);
    }
    return v;
}

void Vector::operator += (const Vector& vec) {
    x += vec.x;
    y += vec.y;
}

void Vector::operator -= (const Vector& vec) {
    x -= vec.x;
    y -= vec.y;
}

void Vector::operator *= (const Vector& vec) {
    x *= vec.x;
    y *= vec.y;
}

void Vector::operator /= (const Vector& vec) {
    if (vec.x == 0.0) {
        x = 0.0;
    } else {
        x /= vec.x;
    }
    
    if (vec.y == 0.0) {
        y = 0.0;
    } else {
        y /= vec.y;
    }
}

bool Vector::operator == (const Vector& vec) const {
    if (x == vec.x && y == vec.y) {
        return true;
    } else {
        return false;
    }
}

// xについて比較する
bool Vector::compareX(const Vector& vec1, const Vector& vec2) {
    return vec1.x < vec2.x || (vec1.x == vec2.x && vec1.y < vec2.y);
}

