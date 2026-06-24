class Solution {
public:
    const int MOD = 1e9 + 7;
    
    typedef vector<vector<long long>> Matrix;
    
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        return C;
    }
    
    Matrix matpow(Matrix M, long long p) {
        int n = M.size();
        Matrix result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) result[i][i] = 1; // identity
        while (p > 0) {
            if (p & 1) result = multiply(result, M);
            M = multiply(M, M);
            p >>= 1;
        }
        return result;
    }
    
    int zigZagArrays(int n, int l, int r) {
        int sz = r - l + 1;
        
        if (n == 1) return sz % MOD;
        
        // State: [up[0], up[1], ..., up[sz-1], down[0], ..., down[sz-1]]
        // Size = 2*sz
        // Transition:
        //   new_up[v]   = sum(down[u] for u < v)  = prefix_down[v]
        //   new_down[v] = sum(up[u]   for u > v)  = suffix_up[v+1]
        
        int S = 2 * sz;
        Matrix T(S, vector<long long>(S, 0));
        
        // new_up[v] depends on down[u] for u < v
        // up[v] is index v, down[v] is index sz+v
        for (int v = 0; v < sz; v++) {
            for (int u = 0; u < v; u++) {
                T[v][sz + u] = 1; // new_up[v] += down[u]
            }
        }
        
        // new_down[v] depends on up[u] for u > v
        for (int v = 0; v < sz; v++) {
            for (int u = v + 1; u < sz; u++) {
                T[sz + v][u] = 1; // new_down[v] += up[u]
            }
        }
        
        // Initial state at length 2:
        // up[v] = v (number of values < v)
        // down[v] = sz - 1 - v
        vector<long long> state(S);
        for (int v = 0; v < sz; v++) {
            state[v] = v;
            state[sz + v] = sz - 1 - v;
        }
        
        // Apply T^(n-2) to state
        Matrix Tn = matpow(T, n - 2);
        
        vector<long long> newstate(S, 0);
        for (int i = 0; i < S; i++)
            for (int j = 0; j < S; j++)
                newstate[i] = (newstate[i] + Tn[i][j] * state[j]) % MOD;
        
        long long ans = 0;
        for (int i = 0; i < S; i++)
            ans = (ans + newstate[i]) % MOD;
        
        return (int)ans;
    }
};
