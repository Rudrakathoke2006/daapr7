#include <stdio.h>
#include <math.h>

#define MAX 50
#define INF 999999

int main() {
    int n;
    scanf("%d", &n);
    
    int keys[MAX];
    double p[MAX], q[MAX+1];
    
    for(int i = 0; i < n; i++)
        scanf("%d", &keys[i]);
    
    for(int i = 0; i < n; i++)
        scanf("%lf", &p[i]);
    
    for(int i = 0; i <= n; i++)
        scanf("%lf", &q[i]);
    
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