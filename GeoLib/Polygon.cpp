#include "Polygon.h"

// 頂点を追加する
void Polygon::addVertex(const Vector& vec) {
    vertex.push_back(vec);
}

// 頂点配列を設定する
void Polygon::setVertex(const vector<Vector>& src) {
    vertex = src;
}

// 面積を計算する
double Polygon::calculateArea() {
    double sum = 0;
    for (int i = 0; i < vertex.size(); i++) {
        Vector vec1, vec2;
        vec1 = vertex[i];
        if (i == vertex.size() - 1) {
            vec2 = vertex[0];
        } else {
            vec2 = vertex[i + 1];
        }
        sum += vec1.cross(vec2);
    }
    return sum / 2.0;
}

// 凸多角形か
bool Polygon::isConvex() {
    for (int i = 0; i < vertex.size(); i++) {
        Vector ver1 = vertex[i];
        Vector ver2 = vertex[(i + 1) % vertex.size()];
        Vector ver3 = vertex[(i + 2) % vertex.size()];
        Vector edge1 = ver2 - ver1;
        Vector edge2 = ver3 - ver1;
        if (edge1.cross(edge2) < 0) {
            return false;
        }
    }
    return true;
}

// 凸包を取得する
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#C++
vector<Vector> Polygon::getConvexHull(vector<Vector>& src) {
    sort(src.begin(), src.end(), Vector::compareX);
    int n = (int)src.size();
    int k = 0;
    vector<Vector> ver(2 * n);
    // 下側凸包を求める
    for (int i = 0; i < n; ++i) {
        while(k >= 2 && (ver[k - 1] - ver[k - 2]).cross(src[i] - ver[k - 2]) < 0.0) { // 3点の外積を求める
            k--; // 反時計周りのとき、src[i]は内側の点なので除く
        }
        ver[k++] = src[i];
    }
    // 上側凸包を求める
    for (int i = n - 1, t = k + 1; i > 0; --i) {
        while(k >= t && (ver[k - 1] - ver[k - 2]).cross(src[i - 1] - ver[k - 2]) < 0.0) { // 3点の外積を求める
            k--; // 反時計周りのとき、src[i - 1]は内側の点なので除く
        }
        ver[k++] = src[i - 1];
    }
    ver.resize(k - 1);
    return ver;
}
