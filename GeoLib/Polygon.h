#ifndef Polygon_h
#define Polygon_h

#include "Vector.h"
#include <vector>

using namespace std;

class Polygon {
private:
    vector<Vector> vertex; // 頂点
public:
    // コンストラクタ
    Polygon() {}
    // 頂点を追加する
    void addVertex(const Vector& vec);
    // 頂点配列を設定する
    void setVertex(const vector<Vector>& src);
    // 面積を計算する
    double calculateArea();
    // 凸多角形か
    bool isConvex();
    // 凸包を取得する
    static vector<Vector> getConvexHull(vector<Vector>& src);
};

#endif /* Polygon_h */
