/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

// Err 3: corner cases. [], [p, p], [p, p, p], [p, p, p1, p2]

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int l = points.size();
        if (l == 0) {
            return 0;
        }
        int max_n = 1;
        for (int i = 1; i < l; ++i) {
            const Point& p1 = points[0];
            const Point& p2 = points[i];
            if (p1.x == p2.x && p1.y == p2.y) {
                max_n++;
            }
        }
        for (int i = 0; i < l - 1; ++i) {
            for (int j = i + 1; j < l; ++j) {
                const Point& p1 = points[i];
                const Point& p2 = points[j];
                if (p1.x == p2.x && p1.y == p2.y) continue;
                int n = 2;
                for (int k = 0; k < l; ++k) {
                    if (k == i || k == j) continue;
                    const Point& p3 = points[k];
                    if ((p1.x - p2.x) * (p3.y - p2.y) == (p1.y - p2.y) * (p3.x - p2.x)) {
                        n++;
                    }
                }
                if (max_n < n) max_n = n;
            }
        }
        return max_n;
    }
};

int main() {
  Solution sol;
  vector<Point> points {{0,9},{138,429},{115,359},{115,359},{-30,-102},{230,709},{-150,-686},{-135,-613},{-60,-248},{-161,-481},{207,639},{23,79},{-230,-691},{-115,-341},{92,289},{60,336},{-105,-467},{135,701},{-90,-394},{-184,-551},{150,774}};
  cout << "output = " << sol.maxPoints(points);
  return 0;
}
