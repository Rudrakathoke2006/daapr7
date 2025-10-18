#include <stdio.h>
#include <math.h>

#define MAX 50
#define INF 999999

int main() {
    int n = 4;
    
    int keys[] = {10, 20, 30, 40};
    double p[] = {0.1, 0.2, 0.4, 0.3};
    double q[] = {0.05, 0.1, 0.05, 0.05, 0.1};
    
    double e[MAX][MAX], w[MAX][MAX];
    int root[MAX][MAX];
    
    for(int i = 1; i <= n; i++) {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
        e[i][i] = q[i-1] + p[i-1] + q[i];
        w[i][i] = q[i-1] + p[i-1] + q[i];
        root[i][i] = i;
    }
    
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            e[i][j] = INF;
            w[i][j] = w[i][j-1] + p[j-1] + q[j];
            
            for(int k = i; k <= j; k++) {
                double cost = e[i][k-1] + e[k+1][j] + w[i][j];
                if(cost < e[i][j]) {
                    e[i][j] = cost;
                    root[i][j] = k;
                }
            }
        }
    }
    
    printf("%.4f\n", e[1][n]);
    
    return 0;
}

