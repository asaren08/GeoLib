#ifndef Math_h
#define Math_h

#include <vector>
#include "Vector.h"

using namespace std;

class Math {
private:
    // コンストラクタ
    Math() {}
    
public:
    // 約数の和を求める
    static int calculateDivisorSum(int num);
    // 最大値を求める
    static float max(const vector<float>& vec);
    // 階乗を求める
    static float calculateFactorial(int n);
    // 数列の差分を求める
    static void getSequence(const vector<float>& src, vector<float>* outVec);
    // 二項展開を計算する
    static float calculateBinominal(int n, int i);
    // バーステイン基底関数を求める
    static float calculateBerstein(int n, int i, float t);
    // 母点を元にベジエ曲線の点列を取得する
    static void getBezieLine(const vector<float>& points, vector<Vector>* outVec);
};

#endif /* Math_h */
