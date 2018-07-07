#ifndef LineSegment_h
#define LineSegment_h

#include "Vector.h"

class LineSegment {
private:
    Vector start; // 始点
    Vector end; // 終点
    
public:
    //コンストラクタ
    LineSegment () {}
    
    // 始点と終点を設定する
    void setStartEnd(double sx, double sy, double ex, double ey);
    // 始点を取得する
    Vector getStart() const { return start; }
    //　終点を取得する
    Vector getEnd() const { return end; }
    // 指定の線分を含むか
    // このメソッドは線分同士が平行の時しか使用しない
    bool isInLine(const LineSegment& l) const;
    // 指定の点を線分の中に含むか
    bool isPointInLine(const Vector& p) const;
    // 指定の線分と交差しているか
    // @return 0(交差していない), 1(交差している)
    int isCross(const LineSegment& l) const;
    // 任意の点が線分の始点より外にあるか
    bool isOutOfStart(const Vector& vec) const;
    // 任意の点との距離を求める
    // http://gihyo.jp/dev/serial/01/as3/0053?page=2
    double getDistance(const Vector& vec) const;
    // 任意の線分との距離を求める
    double getDistance(const LineSegment& l) const;
};

#endif /* LineSegment_h */
