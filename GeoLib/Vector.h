#ifndef Vector_h
#define Vector_h

#include <math.h>

// 2次元ベクトルクラス
class Vector {
public:
    double x, y;
    // コンストラクタ
    Vector();
    // コピーコンストラクタ
    Vector(const Vector& v);
    // コンストラクタ(引数あり)
    Vector(double nx, double ny);
    // デストラクタ
    ~Vector() {};
    // x,yを設定する
    void set(double nx, double ny);
    // xを設定する
    void setX(double nx) { x = nx; }
    // yを設定する
    void setY(double ny) { y = ny; }
    // 回転する
    void rotate(double radian);
    // ベクトルの大きさを求める
    double norm() const;
    // 内積を求める
    double dot(const Vector& vec) const;
    // 外積を求める
    double cross(const Vector& vec) const;
    // 余弦を求める
    double getCos(const Vector& vec) const;
    // 単位ベクトルを返す
    Vector getUnit() const;
    // ベクトル1をベクトル2に正射影したベクトルを求める
    static Vector getProjection(const Vector& vec1, const Vector& vec2);
    // =演算子のオーバーロード
    void operator = (const Vector& vec);
    // +演算子のオーバーロード
    Vector operator + (const Vector& vec) const;
    // -演算子のオーバーロード
    Vector operator - (const Vector& vec) const;
    // +演算子のオーバーロード
    Vector operator * (const Vector& vec) const;
    // *演算子のオーバーロード
    Vector operator * (double f) const;
    // /演算子のオーバーロード
    Vector operator / (const Vector& vec) const;
    // /演算子のオーバーロード
    Vector operator / (double f) const;
    // +=演算子のオーバーロード
    void operator += (const Vector& vec);
    // -=演算子のオーバーロード
    void operator -= (const Vector& vec);
    // *=演算子のオーバーロード
    void operator *= (const Vector& vec);
    // /=演算子のオーバーロード
    void operator /= (const Vector& vec);
    // ==演算子のオーバーロード
    bool operator == (const Vector& vec) const;
    // xについて比較する
    static bool compareX (const Vector& vec1, const Vector& vec2);
};


#endif /* Vector_h */
