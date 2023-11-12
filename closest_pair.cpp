#include <bits/stdc++.h>
using namespace std;

struct P {
    float x, y;
};

double sq(double a) {
    return a * a;
}

double distance(const P& a, const P& b) {
    return sq(a.x - b.x) + sq(a.y - b.y);
}

pair<P, P> closest_pair;  // Store the closest pair of points
double min_distance = DBL_MAX;

double smallest_distance(vector<P> points, vector<P> points_by_y) {
    int n = points.size();
    if (n <= 1) {
        return DBL_MAX / 2;
    }

    vector<P> left = vector<P>(points.begin(), points.begin() + n / 2);
    vector<P> right = vector<P>(points.begin() + n / 2, points.end());
    vector<P> left_by_y, right_by_y;
    for (P p : points_by_y) {
        if (make_pair(p.x, p.y) <= make_pair(left.back().x, left.back().y)) {
            left_by_y.push_back(p);
        } else {
            right_by_y.push_back(p);
        }
    }

    double d1 = smallest_distance(left, left_by_y);
    double d2 = smallest_distance(right, right_by_y);
    double d = min(d1, d2);

    float middle_x = left.back().x;
    vector<P> stripe;
    for (P p : points_by_y) {
        if (sq(p.x - middle_x) < d) {
            stripe.push_back(p);
        }
    }

    for (int i = 0; i < (int)stripe.size(); ++i) {
        for (int j = i + 1; j < (int)stripe.size() && sq(stripe[j].y - stripe[i].y) < d; ++j) {
            d = min(d, distance(stripe[i], stripe[j));
            if (d < min_distance) {
                min_distance = d;
                closest_pair = make_pair(stripe[i], stripe[j]);
            }
        }
    }
    return d;
}

int main() {
    int n;
    cin >> n;
    vector<P> points(n);
    for (P& p : points) {
        scanf("%f%f", &p.x, &p.y);
    }
    sort(points.begin(), points.end(), [&](const P& a, const P& b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    vector<P> points_by_y = points;
    sort(points_by_y.begin(), points_by_y.end(), [&](const P& a, const P& b) {
        return a.y < b.y;
    });

    smallest_distance(points, points_by_y);

    cout << "Smallest distance: " << min_distance << endl;
    cout << "Closest pair of points: (" << closest_pair.first.x << ", " << closest_pair.first.y << ") and ("
         << closest_pair.second.x << ", " << closest_pair.second.y << ")" << endl;

    return 0;
}
