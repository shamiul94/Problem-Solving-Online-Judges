#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <bits/stdc++.h>

#define size_data 22 * 7

using namespace std;


double minimum_val, maximum_val, mean_val, median_val, SD, skewness;

double given_data[size_data] = {
        2.31, 0.94, 1.55, 1.1, 1.68, -0.16, 0.48,
        1.49, 1.2, 1.48, 0.85, 3.21, 1.71, 4.0,
        2.1, 0.26, 1.97, 1.09, 2.72, 1.18, 0.28,
        0.3, 1.4, 0.59, 1.99, 2.14, 1.59, 1.5,
        0.48, 2.12, 1.15, 2.54, 0.7, 1.63, 1.47,
        1.71, 1.41, 0.95, 1.55, 1.28, 0.44, -1.72,
        0.19, 2.73, 0.45, 0.49, 1.23, 2.44, -1.62,
        0.0, 1.33, -0.51, 1.62, 0.06, 2.2, 1.87,
        0.66, 0.26, 2.36, 2.4, 1.0, 2.3, 1.74,
        -1.27, 3.11, 1.03, 0.59, 1.37, 1.3, 0.78,
        1.01, 0.99, 0.24, 2.18, 2.24, 0.22, 1.0,
        -0.54, 0.24, 2.66, 1.14, 1.06, 1.09, 1.63,
        1.7, 1.35, 1.0, 1.21, 1.75, 3.27, 1.62,
        2.58, 0.6, 0.19, 1.43, 2.21, 0.49, 0.46,
        0.56, 1.17, 2.28, 2.02, 1.71, 1.08, 2.0,
        0.38, 1.12, 0.01, 1.82, 1.96, 0.77, 1.7,
        0.77, 2.79, 0.31, 1.11, 1.69, 1.23, 2.05,
        2.29, 0.17, -0.12, 2.69, 1.78, 2.26, 0.0,
        1.55, 0.44, 0.89, 1.51, -0.67, 1.06, -0.05,
        0.27, 0.78, 0.6, 1.06, 2.29, 1.13, 1.85,
        1.62, 1.5, 0.21, 2.04, 1.26, 1.98, 1.5,
        0.94, 0.17, 1.9, 1.64, 1.12, 0.89, 0.4};

int lower_bound(double key);

int upper_bound(double key);

void draw_barchart(double b) {
    double diff = maximum_val - minimum_val;
    int bar_no = (int) (diff / b) + 1;

    int max_frequency = -1, min_frequency = 10000;
    int bar_chart[bar_no];

    double l = minimum_val;
    for (int i = 0; i < bar_no; i++) {
        bar_chart[i] = (upper_bound(l + b - 0.01) - lower_bound(l));
        if (bar_chart[i] > max_frequency)
            max_frequency = bar_chart[i];
        else if (bar_chart[i] < min_frequency)
            min_frequency = bar_chart[i];
        l += b;
    }
    for (int k = max_frequency; k >= min_frequency; k--) {
        for (int i = 0; i < bar_no; i++) {
            if (bar_chart[i] >= k) {
                cout << "# ";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int cmp(const void *a, const void *b) {
    double A = *(double *) a;
    double B = *(double *) b;
    if (A < B)
        return -1;
    else if (A > B)
        return 1;
    return 0;
}

void get_summary_stat() {

    mean_val = 0.0;
    for (double i : given_data)
        mean_val += i;
    mean_val /= size_data;
    median_val = (given_data[size_data / 2] + given_data[(size_data / 2) - 1]) / 2;

    SD = 0.0;
    for (double i : given_data) {
        SD += (i - mean_val) * (i - mean_val);
    }
    SD /= size_data;
    SD = sqrt(SD);

    skewness = 0.0;
    for (double i : given_data) {
        skewness += (i - mean_val) * (i - mean_val) * (i - mean_val);
    }
    skewness /= (SD * SD * SD);
    skewness *= size_data / ((size_data - 1) * (size_data - 2));
    skewness = (skewness == -0.0) ? 0.0 : skewness;
}

double integrateNormal(double b, double a, double miu, double sigma) {

    double upperInt = 0.5 * (1 + erf((b - miu) / (sigma * sqrt(2.0))));
    double lowerInt = 0.5 * (1 + erf((a - miu) / (sigma * sqrt(2.0))));
    return upperInt - lowerInt;
}


int lower_bound(double key) {
    int l = 0, r = size_data - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (given_data[mid] >= key)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int upper_bound(double key) {
    int lo = 0, hi = size_data - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (given_data[mid] <= key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}


void chiralSqrTest() {
    double width = 0.3;
    double difference = maximum_val - minimum_val;
    int num_bars = (int) (difference / 0.3);
    printf("Range diff: %f, bars No: %d\n", difference, num_bars);

    int max_frequency = -1, min_frequency = 10000;
    double N_j[num_bars];

    double l = minimum_val;
    for (int i = 0; i < num_bars; i++) {

        N_j[i] = (double) (upper_bound(l + width - 0.01) - lower_bound(l));
        if (N_j[i] > max_frequency)
            max_frequency = N_j[i];
        else if (N_j[i] < min_frequency)
            min_frequency = N_j[i];
        l += width;
    }

    double n_p_j[num_bars];
    l = minimum_val;
    for (int i = 0; i < num_bars; i++) {

        n_p_j[i] = size_data * integrateNormal(l + width, l, mean_val, SD);
        l += width;
    }

    double chi_squared = 0.0;
    for (int i = 0; i < num_bars; i++) {
        chi_squared += (((N_j[i] - n_p_j[i]) * (N_j[i] - n_p_j[i])) / n_p_j[i]);
    }
    printf("chi_squared: %0.3f\n", chi_squared);
}

class Summary {
public:
    Summary() = default;

    static void process() {
        draw_barchart(0.3);
        get_summary_stat();
        chiralSqrTest();
    }

};

int main() {
    qsort(given_data, size_data, sizeof(double), cmp);
    minimum_val = given_data[0];
    maximum_val = given_data[size_data - 1];

    Summary s;
    Summary::process();

    return 0;
}