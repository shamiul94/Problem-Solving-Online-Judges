using namespace std;
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi = -1.0;
        for(int i = 0 ; i < points.size(); i++){
            vector<int> A = points[i];
            for(int j = i+1; j < points.size(); j++){
                vector<int> B = points[j];
                for(int k = j+1; k < points.size(); k++){
                    vector<int> C = points[k];

                    double Ax, Ay, Bx, By, Cx, Cy;
                    Ax = A[0]; Ay = A[1];
                    Bx = B[0]; By = B[1];
                    Cx = C[0]; Cy = C[1];

                    double area = abs((Ax*(By-Cy)+Bx*(Cy-Ay)+Cx*(Ay-By))/2.0);
                    maxi = max(area, maxi);
                }
            }
        }
        return maxi;
    }
};