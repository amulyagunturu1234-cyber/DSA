class Fancy {
    private:
    vector<long long> vals;       // raw stored values
    vector<long long> mults;      // cumulative mult at time of append
    vector<long long> adds;       // cumulative add at time of append
    
    long long curMult;
    long long curAdd;
    const long long MOD = 1e9 + 7;
    
    // Fermat's little theorem for modular inverse (MOD is prime)
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
     long long modInverse(long long a, long long mod) {
        return power(a, mod - 2, mod);
    }
public:
    Fancy() {
         curMult = 1;
        curAdd = 0;
    }
    
    void append(int val) {
         vals.push_back(val);
        mults.push_back(curMult);
        adds.push_back(curAdd);
    }
    
    void addAll(int inc) {
        curAdd = (curAdd + inc) % MOD;
    }
    
    void multAll(int m) {
        curMult = curMult * m % MOD;
        curAdd = curAdd * m % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= (int)vals.size()) return -1;
        
        /*
         * At append time:  transforms were (mults[idx], adds[idx])
         * Current transforms: (curMult, curAdd)
         *
         * true_value = vals[idx] * (curMult / mults[idx])
         *            + (curAdd - adds[idx] * (curMult / mults[idx]))
         *
         * i.e. only the "delta" transforms applied AFTER append matter
         */
        long long invMult = modInverse(mults[idx], MOD);
        
        // relative multiplier since this element was appended
        long long relMult = curMult * invMult % MOD;
        
        // relative adder since this element was appended
        long long relAdd = (curAdd - adds[idx] * relMult % MOD + MOD) % MOD;
        
        long long result = (vals[idx] * relMult % MOD + relAdd) % MOD;
        return (int)result;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
