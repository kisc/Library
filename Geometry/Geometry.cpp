struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    double norm() const { return sqrt(x * x + y * y); }
    Point unit() const {
        double l = norm();
        return Point(x / l, y / l);
    }
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-() const { return Point(-x, -y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double a) const { return Point(a * x, a * y); }
    Point operator/(double a) const { return Point(x / a, y / a); }
    static double Distance(const Point& a, const Point& b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    static double Dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
    static double Cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
    static int CCW(Point a, Point b, Point c){
        b = b - a; c = c - a;
        if (Cross(b, c) > EPS) return +1;      // 反時計周り
        if (Cross(b, c) < -EPS) return -1;     // 時計周り
        if (Dot(b, c) < 0) return +2;          // c--a--b 直線
        if (b.norm() < c.norm()) return -2;    // a--b--c 直線
        return 0;                              // a--c--b 直線
    }
};
istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
ostream& operator<<(ostream& os, const Point &p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

struct Line {
    Point a, b;
    Line() : a(Point(0, 0)), b(Point(0, 0)) {}
    Line(Point a, Point b) : a(a), b(b) {}
    Point Projection(const Point& p) const {
        Point s = b - a,
              t = p - a;
        double n = s.norm();
        return a + s * (Point::Dot(s, t) / (n * n));
    }
    Point Reflection(const Point& p) const {
        Point q = Projection(p);
        Point v = q - p;
        return q + v;
    }
    static Point Intersection(const Line& l, const Line& m) {
        double d = Point::Cross(m.b - m.a, l.b - l.a);
        assert(abs(d) >= EPS); // 線分が平行でないことを確認
        return l.a + (l.b - l.a) * (Point::Cross(m.b - m.a, m.b - l.a) / d);
    }
};
struct Segment : Line {
    Segment(Point a, Point b) : Line(a, b) {}
    static bool DoIntersect(const Segment& l, const Segment& m) {
        return Point::CCW(l.a, l.b, m.a) * Point::CCW(l.a, l.b, m.b) <= 0 &&
               Point::CCW(m.a, m.b, l.a) * Point::CCW(m.a, m.b, l.b) <= 0;
    static double Distance(const Segment& s, const Point& p) {
        Point q = s.Projection(p);
        Segment t(p, q);
        if (DoIntersect(s, t)) return t.length();
        return min(Point::Distance(s.a, p), Point::Distance(s.b, p));
    }
    static double Distance(const Segment& s, const Segment& t) {
        if (DoIntersect(s, t)) return 0;
        return min( min(Distance(s, t.a), Distance(s, t.b)),
                    min(Distance(t, s.a), Distance(t, s.b)) );
    }
};
