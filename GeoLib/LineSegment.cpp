#include <math.h>
#include "LineSegment.h"

// 始点と終点を設定する
void LineSegment::setStartEnd(double sx, double sy, double ex, double ey) {
    start.set(sx, sy);
    end.set(ex, ey);
}

// 指定の線分を含むか
// このメソッドは線分同士が平行の時しか使用しない
bool LineSegment::isInLine(const LineSegment& l) const {
    bool b1 = isPointInLine(l.getStart());
    bool b2 = isPointInLine(l.getEnd());
    if (b1 || b2) {
        return true;
    } else {
        return false;
    }
}

// 指定の点を線分の中に含むか
bool LineSegment::isPointInLine(const Vector& p) const {
    if (start == p) {
        return true;
    }
    
    Vector l1 = end - start;
    Vector l2 = p - start;
    Vector u1 = l1.getUnit();
    Vector u2 = l2.getUnit();
    
    if (u1 == u2 && l2.norm() <= l1.norm()) {
        return true;
    } else {
        return false;
    }
}

// 指定の線分と交差しているか
// @return 0(交差していない), 1(交差している)
int LineSegment::isCross(const LineSegment& l) const {
    Vector l1 = end - start;
    double c1 = l1.cross(l.getStart() - start);
    double c2 = l1.cross(l.getEnd() - start);
    
    Vector l2 = l.getEnd() - l.getStart();
    double c3 = l2.cross(start - l.getStart());
    double c4 = l2.cross(end - l.getStart());
    
    if (c1 * c2 == 0.0 && c3 * c4 == 0.0) { // 平行のとき
        LineSegment ls;
        ls.setStartEnd(start.x, start.y, end.x, end.y);
        if (isInLine(l) || l.isInLine(ls)) {
            return 1;
        }
        return 0;
    } else if ((c1 * c2 < 0.0 && c3 * c4 <= 0.0)
               || (c1 * c2 <= 0.0 && c3 * c4 < 0.0)
               || (c1 * c2 < 0.0 && c3 * c4 < 0.0)) { // 交差するとき
        return 1;
    } else { // 交差しないとき
        return 0;
    }
}

// 任意の点が線分の始点より外にあるか
bool LineSegment::isOutOfStart(const Vector& vec) const {
    Vector p = end - start;
    Vector q = vec - start;
    double d = p.dot(q);
    if (d < 0) { // 内積が負のとき
        return true;
    }
    return false;
}

// 任意の点との距離を求める
// http://gihyo.jp/dev/serial/01/as3/0053?page=2
double LineSegment::getDistance(const Vector& vec) const {
    if (isPointInLine(vec)) { // 線分内に点を含むとき
        return 0.0;
    }
    if (!isOutOfStart(vec)) { // 線分の始点より内側に点があるとき
        Vector p = end - start;
        Vector q = vec - start;
        Vector proj = Vector::getProjection(q, p);
        if (p.norm() > proj.norm()) { // 正射影したベクトルが線分より短いとき
            return (q - proj).norm();
        } else { // 正射影したベクトルが線分と等しいか、長いとき
            return (vec - end).norm();
        }
    } else { // 線分の始点より外にあるとき
        return (vec - start).norm();
    }
}

// 任意の線分との距離を求める
double LineSegment::getDistance(const LineSegment& l) const {
    if (isCross(l)) { // 交差しているとき
        return 0.0;
    }
    
    LineSegment ls;
    ls.setStartEnd(start.x, start.y, end.x, end.y);
    double dis1 = getDistance(l.getStart());
    double dis2 = getDistance(l.getEnd());
    double dis3 = l.getDistance(ls.getStart());
    double dis4 = l.getDistance(ls.getEnd());
    
    double min1 = fmin(dis1, dis2);
    double min2 = fmin(dis3, dis4);
    return fmin(min1, min2);
}
