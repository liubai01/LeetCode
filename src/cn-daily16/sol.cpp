#include <iostream>
#include <string>
#include <vector>
#include<cmath>

#define OJ false

using namespace std;


class Solution {
public:
    bool in_range(int v, int v1, int v2) {
        if (v >= min(v1, v2) && v <= max(v1, v2))
            return true;
        return false;
    }

    bool is_IOU(double v1_1, double v1_2, double v2_1, double v2_2) {
        double v1_min = min(v1_1, v1_2);
        double v1_max = max(v1_1, v1_2);
        double v2_min = min(v2_1, v2_2);
        double v2_max = max(v2_1, v2_2);

        if (v2_max < v1_min) {
            return false;
        } 
        if (v1_max < v2_min) {
            return false;
        }
        return true;
    }

    double min_IOU(double v1_1, double v1_2, double v2_1, double v2_2) {
        double v1_min = min(v1_1, v1_2);
        double v1_max = max(v1_1, v1_2);
        double v2_min = min(v2_1, v2_2);
        double v2_max = max(v2_1, v2_2);

        if (v2_min >= v1_min) {
            return v2_min;
        } else {
            return v1_min;
        }
        return v1_min;
    }

    double get_k(int x1, int x2, int y1, int y2) {
        return ((double) y2 - (double) y1) / ((double) x2 - (double) x1);
    }

    double get_b(int x1, int x2, int y1, int y2) {
        double k = get_k(x1, x2, y1, y2);
        return -k * ((double) x1) +((double) y1);
    }

    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int l1_x1 = start1[0];
        int l1_y1 = start1[1];
        int l1_x2 = end1[0];
        int l1_y2 = end1[1];

        int l2_x1 = start2[0];
        int l2_y1 = start2[1];
        int l2_x2 = end2[0];
        int l2_y2 = end2[1];

        vector<double> retPt = {};

        // Case [1]: line 1 is verticle
        if (l1_x1 == l1_x2) {
            if (not OJ) cout << "Case [1]: line 1 is verticle" << endl;
            // Case [1.1]: line 2 is horizontal
            if (l2_y1 == l2_y2) {
                if (not OJ) cout << "Case [1.1]: line 2 is horizontal" << endl;

                // Case [1.1.2]: line2 y lies in line 1 y range 
                if (in_range(l2_y1, l1_y1, l1_y2)) {
                    if (not OJ) cout << "Case [1.1.2]:  line2 y lies in line 1 y range" << endl;
                    // line 1 x lies in lie 2 x range
                    if (in_range(l1_x1, l2_x1, l2_x2)) {
                        if (not OJ) cout << "Case [1.1.2] (1):  line1 x lies in line2 x range" << endl;
                        retPt = {(double) l1_x1, (double) l2_y1};
                        return retPt;
                    } else {
                        if (not OJ) cout << "Case [1.1.2] (2):  line1 x out of line2 x range" << endl;
                        return retPt;
                    }
                } else { // Case [1.1.1]: line2 y out of line 1 y range 
                    if (not OJ) cout << "Case [1.1.1]:  line2 y out of line 1 y range" << endl;
                    return retPt;
                }

            } else if (l2_x1 == l2_x2) { // Case [1. 3]: line 2 is verticle
                if (not OJ) cout << "Case [1.3]: line 2 is verticle as well." << endl;

                if (l2_x1 != l1_x1) { // Case [1.3.1]: line 2 x != line 1's
                    if (not OJ) cout << "Case [1.3.1]: line 2 x != line 1's" << endl;
                    return retPt;
                } else { // Case [1.3.2]: line 2 x == line 1's
                    if (is_IOU(l1_y1, l1_y2, l2_y1, l2_y2)) {
                        // has intersaction
                        if (not OJ) cout << "Case [1.3.2]: Intersaction!" << endl;
                        retPt = {(double)l2_x1, min_IOU((double)l1_y1, (double)l1_y2, (double)l2_y1, (double)l2_y2)};
                        return retPt;
                    } else {
                        if (not OJ) cout << "Case [1.3.2]: No intersaction!" << endl;
                        return retPt;
                    }
                }
            } else { // Case [1. 2]: line 2 is leaky
                if (not OJ) cout << "Case [1.2]: line 2 is leaky." << endl;
                double k2 = get_k(l2_x1, l2_x2, l2_y1, l2_y2);
                double b2 = get_b(l2_x1, l2_x2, l2_y1, l2_y2);
                double p_y = k2 * ((double)l1_x1) + b2;
                if (in_range(p_y, l1_y1, l1_y2)) {
                    if (not OJ) cout << "Case [1.2.1]: line 2 intersaction." << endl;
                    retPt = {(double)l1_x1, (double) p_y};
                    return retPt;
                } else {
                    if (not OJ) cout << "Case [1.2.1]: line 2 no intersaction." << endl;
                    return retPt;
                }
            }
        } else if (l2_x1 == l2_x2) { // Case [2]: line 2 is verticle
            if (not OJ) cout << "Case [2]: line 2 is verticle" << endl;
            if (l1_y1 == l1_y2) { // Case[2.1]: line 1 is horizontal
                if (not OJ) cout << "Case [2.1]: line 1 is horizontal" << endl;
                if (in_range(l1_y1, l2_y1, l2_y2)) {
                    if (not OJ) cout << "Case [2.1]: line 1 y in line 2 range" << endl;
                    if (in_range(l2_x1, l1_x1, l1_x2)) {
                        if (not OJ) cout << "Case [2.1]: line 2 x in line 1 range" << endl;
                        retPt = {(double)l1_y1, (double) l2_x1};
                        return retPt;
                    } else {
                        if (not OJ) cout << "Case [2.1]: line 2 x out of line 1 range" << endl;
                        return retPt;
                    }
                } else {
                    if (not OJ) cout << "Case [2.1]: line 1 y out of line 2 range" << endl;
                    return retPt;
                }
            } else { // Case[2.2]: line 1 is leaky
                if (not OJ) cout << "Case [2.2]: line 1 is leaky." << endl;
                double k1 = get_k(l1_x1, l1_x2, l1_y1, l1_y2);
                double b1 = get_b(l1_x1, l1_x2, l1_y1, l1_y2);
                double p_y = k1 * ((double)l2_x1) + b1;
                if (in_range(p_y, l2_y1, l2_y2)) {
                    if (not OJ) cout << "Case [2.2]: line 2 intersaction." << endl;
                    retPt = {(double)l2_x1, (double) p_y};
                    return retPt;
                } else {
                    if (not OJ) cout << "Case [2.2]: line 2 not intersaction." << endl;
                    return retPt;
                }
            }
        } else {
            if (not OJ) cout << "Case [2]: line 1 is leaky(horizontal) and line 2 is leak(horizontal)" << endl;

            double k1 = get_k(l1_x1, l1_x2, l1_y1, l1_y2);
            double b1 = get_b(l1_x1, l1_x2, l1_y1, l1_y2);
            double k2 = get_k(l2_x1, l2_x2, l2_y1, l2_y2);
            double b2 = get_b(l2_x1, l2_x2, l2_y1, l2_y2);

            if (fabs(k1 - k2) < 1e-6) {
                if (not OJ) cout << "Case [2.1]: parallel" << endl;
                if (fabs(b1 - b2) < 1e-6) {
                    if (is_IOU(l1_y1, l1_y2, l2_y1, l2_y2)) {
                        // has intersaction
                        if (not OJ) cout << "Case [2.1]: Intersaction!" << endl;
                        double p_x = min_IOU((double)l1_x1, (double)l1_x2, (double)l2_x1, (double)l2_x2);
                        double p_y = k1 * p_x + b1;
                        retPt = {p_x, p_y};
                        return retPt;
                    } else {
                        if (not OJ) cout << "Case [2.1]: No intersaction!" << endl;
                        return retPt;
                    }
                } else {
                    if (not OJ) cout << "Case [2.1]: no intersactoin" << endl;
                    return retPt;
                }
            } else {
                double p_x = (b2 - b1) / (k1 - k2);
                double p_y = k1 * p_x + b1;

                if (in_range(p_x, l1_x1, l1_x2) && in_range(p_x, l2_x1, l2_x2) && in_range(p_y, l1_y1, l1_y2) && in_range(p_y, l2_y1, l2_y2)) {
                    if (not OJ) cout << "Case [2.1]: intersaction" << endl;
                    retPt = {(double)p_x, (double) p_y};
                    return retPt;
                } else {
                    if (not OJ) cout << "Case [2.1]: no intersaction" << endl;
                    return retPt;
                }
            }
        }

        return retPt;
    }

};