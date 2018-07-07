#include <math.h>
#include "Vector.h"
#include "Math.h"

// 約数の和を求める
int Math::calculateDivisorSum(int num) {
    int ret = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) { // 割り切れるとき
            ret += i;
        }
    }
    return ret;
}

// 最大値を求める
float Math::max(const vector<float>& vec) {
    int max = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (max < vec[i]) {
            max = vec[i];
        }
    }
    return max;
}

// 階乗を求める
float Math::calculateFactorial(int n) {
    float ret = 1.0;
    for (int i = 2; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

// 数列の差分を求める
void Math::getSequence(const vector<float>& src, vector<float>* outVec) {
    for (int i = (int)src.size() - 1; i > 0; i--) {
        float diff = src[i] - src[i - 1];
        outVec->push_back(diff);
    }
}

// 二項展開を計算する
float Math::calculateBinominal(int n, int i) {
    // 余分な部分を(n - i)で消す
    float numer = calculateFactorial(n);
    float denom = calculateFactorial(i) * calculateFactorial(n - i);
    return numer / denom;
}

// バーステイン基底関数を求める
float Math::calculateBerstein(int n, int i, float t) {
    // 二項係数 * t^i * (1-t)^(n-i)
    float b = calculateBinominal(n, i);
    float t0 = pow(t, i);
    float t1 = pow(1 - t, n - i);
    return b * t0 * t1;
}

// 母点を元にベジエ曲線の点列を取得する
void Math::getBezieLine(const vector<float>& points, vector<Vector>* outVec) {
    for (float t = 0; t < 1; t += 0.01) {
        float x = 0.f;
        float y = 0.f;
        for (int i = 0; i < points.size(); i++) {
            x += points[i] * calculateBerstein((int)points.size() - 1, i, t);
            y += points[i] * calculateBerstein((int)points.size() - 1, i, t);
        }
        outVec->push_back(Vector(x, y));
    }
}

