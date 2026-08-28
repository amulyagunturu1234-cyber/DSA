class Solution {
public:

    string makePalindrome(string left, char mid) {
        string right = left;
        reverse(right.begin(), right.end());

        return left + (mid ? string(1, mid) : "") + right;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Frequency of characters in s
        vector<int> cnt(26, 0);

        for(char c : s)
            cnt[c - 'a']++;

        // Check whether palindrome is possible
        int odd = 0;
        char mid = 0;

        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if(odd > 1)
            return "";

        // Build frequency of characters available
        // in the LEFT HALF
        vector<int> halfCnt(26, 0);

        for(int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int half = n / 2;

        string targetLeft = target.substr(0, half);

        // ------------------------------------------------
        // CASE 1:
        // Can targetLeft itself be formed?
        // ------------------------------------------------

        vector<int> temp = halfCnt;
        bool possible = true;

        for(char c : targetLeft) {
            if(temp[c - 'a'] == 0) {
                possible = false;
                break;
            }

            temp[c - 'a']--;
        }

        if(possible) {

            string candidate = makePalindrome(targetLeft, mid);

            if(candidate > target)
                return candidate;
        }

        // ------------------------------------------------
        // CASE 2:
        // Find smallest left half > targetLeft
        // ------------------------------------------------

        /*
            We want:

                left > targetLeft

            while using exactly halfCnt characters.

            Find the position from RIGHT where we can
            increase targetLeft[i].

            Everything after i should be made as small
            as possible.
        */

        vector<int> remaining = halfCnt;

        // First, try matching targetLeft as much as possible
        for(int i = 0; i < half; i++) {

            int x = targetLeft[i] - 'a';

            // We cannot match targetLeft[i]
            if(remaining[x] == 0)
                break;

            remaining[x]--;
        }

        /*
            Instead of trying to handle the broken prefix,
            we directly scan the pivot from right to left.
        */

        remaining = halfCnt;

        // Count characters used by prefix while moving right
        for(int i = 0; i < half; i++) {

            int x = targetLeft[i] - 'a';

            // If we cannot match this position,
            // no further equal prefix is possible.
            if(remaining[x] == 0)
                break;

            remaining[x]--;
        }

        // Easier robust method:
        // Try every pivot from right to left.
        for(int pivot = half - 1; pivot >= 0; pivot--) {

            // Recreate counts for targetLeft[0 ... pivot-1]
            vector<int> rem = halfCnt;

            bool ok = true;

            for(int i = 0; i < pivot; i++) {

                int x = targetLeft[i] - 'a';

                if(rem[x] == 0) {
                    ok = false;
                    break;
                }

                rem[x]--;
            }

            if(!ok)
                continue;

            int cur = targetLeft[pivot] - 'a';

            // At pivot, choose the smallest character
            // strictly greater than targetLeft[pivot]
            for(int c = cur + 1; c < 26; c++) {

                if(rem[c] == 0)
                    continue;

                string left = targetLeft.substr(0, pivot);

                left += char('a' + c);

                rem[c]--;

                // Fill remaining positions with
                // smallest possible characters
                for(int k = 0; k < 26; k++) {
                    while(rem[k] > 0) {
                        left += char('a' + k);
                        rem[k]--;
                    }
                }

                return makePalindrome(left, mid);
            }
        }

        return "";
    }
};