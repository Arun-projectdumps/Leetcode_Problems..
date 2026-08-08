class Solution {
public:
    // Index:
    // 0 -> factor 2
    // 1 -> factor 3
    // 2 -> factor 5
    // 3 -> factor 7
    using A = array<long long, 4>;

    // Prime factorization of t using only 2,3,5,7.
    // If something remains, t contains another prime factor
    // and the answer is impossible.
    A getPrimeCount(long long t, bool &ok) {
        A cnt = {0, 0, 0, 0};

        long long primes[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {
            while (t % primes[i] == 0) {
                t /= primes[i];
                cnt[i]++;
            }
        }

        ok = (t == 1);
        return cnt;
    }

    // Prime factors contributed by each digit.
    A digitFactor(int d) {
        static const A f[10] = {
            {0, 0, 0, 0}, // 0
            {0, 0, 0, 0}, // 1
            {1, 0, 0, 0}, // 2
            {0, 1, 0, 0}, // 3
            {2, 0, 0, 0}, // 4
            {0, 0, 1, 0}, // 5
            {1, 1, 0, 0}, // 6
            {0, 0, 0, 1}, // 7
            {3, 0, 0, 0}, // 8
            {0, 2, 0, 0}  // 9
        };

        return f[d];
    }

    // Convert required prime factors into the minimum number
    // of digits needed.
    //
    // Examples:
    // 2^3 -> 8
    // 3^2 -> 9
    // 2^2 -> 4
    // 2*3 -> 6
    int digitsNeeded(A c) {
        int ans = 0;

        // 2^3 = 8
        ans += c[0] / 3;
        c[0] %= 3;

        // 3^2 = 9
        ans += c[1] / 2;
        c[1] %= 2;

        // 5 and 7 must remain separate.
        ans += (int)c[2];
        ans += (int)c[3];

        // Remaining factors of 2 and 3.
        //
        // At this point c[0] <= 2 and c[1] <= 1.

        // 2 * 3 = 6
        if (c[0] >= 1 && c[1] >= 1) {
            ans++;
            c[0]--;
            c[1]--;
        }

        // 2 * 2 = 4
        ans += c[0] / 2;
        c[0] %= 2;

        // Remaining single 2 or 3.
        ans += (int)c[0];
        ans += (int)c[1];

        return ans;
    }

    // Build the smallest string whose digit product contains
    // all factors in c.
    string build(A c) {
        string res;

        // Use 8 for groups of three 2s.
        while (c[0] >= 3) {
            res += '8';
            c[0] -= 3;
        }

        // Use 9 for groups of two 3s.
        while (c[1] >= 2) {
            res += '9';
            c[1] -= 2;
        }

        // 5
        while (c[2] > 0) {
            res += '5';
            c[2]--;
        }

        // 7
        while (c[3] > 0) {
            res += '7';
            c[3]--;
        }

        // Remaining 2 and 3 -> 6
        if (c[0] >= 1 && c[1] >= 1) {
            res += '6';
            c[0]--;
            c[1]--;
        }

        // Remaining pairs of 2 -> 4
        while (c[0] >= 2) {
            res += '4';
            c[0] -= 2;
        }

        // Remaining single 2
        while (c[0] > 0) {
            res += '2';
            c[0]--;
        }

        // Remaining single 3
        while (c[1] > 0) {
            res += '3';
            c[1]--;
        }

        // Arrange digits in increasing order to get the
        // smallest possible number.
        sort(res.begin(), res.end());

        return res;
    }

    // Return true if 'have' contains all factors in 'need'.
    bool contains(A have, A need) {
        for (int i = 0; i < 4; i++) {
            if (have[i] < need[i])
                return false;
        }

        return true;
    }

    string smallestNumber(string num, long long t) {

        // --------------------------------------------------
        // 1. Factorize t
        // --------------------------------------------------

        bool ok;
        A need = getPrimeCount(t, ok);

        // t contains a prime factor other than 2,3,5,7.
        // No digit product can contain that prime.
        if (!ok)
            return "-1";


        // --------------------------------------------------
        // 2. Find minimum number of digits needed to
        //    construct a product divisible by t.
        // --------------------------------------------------

        int minDigits = digitsNeeded(need);


        // --------------------------------------------------
        // 3. If we need more digits than num has,
        //    the answer must have more digits.
        // --------------------------------------------------

        if (minDigits > (int)num.size()) {
            // minDigits is already the minimum possible length.
            // Put the required digits in increasing order.
            return build(need);
        }


        // --------------------------------------------------
        // 4. Count the prime factors already present in num.
        // --------------------------------------------------

        A total = {0, 0, 0, 0};

        int firstZero = (int)num.size();

        for (int i = 0; i < (int)num.size(); i++) {

            int d = num[i] - '0';

            if (d == 0) {
                firstZero = min(firstZero, i);
            }

            A f = digitFactor(d);

            for (int j = 0; j < 4; j++) {
                total[j] += f[j];
            }
        }


        // --------------------------------------------------
        // 5. If num itself is zero-free and divisible,
        //    it is automatically the answer.
        // --------------------------------------------------

        if (firstZero == (int)num.size() &&
            contains(total, need)) {
            return num;
        }


        // --------------------------------------------------
        // 6. Try to change one digit.
        //
        // Start from the RIGHT.
        //
        // Changing a digit farther right gives the smallest
        // possible number.
        // --------------------------------------------------

        A prefixFactors = total;

        for (int i = (int)num.size() - 1; i >= 0; i--) {

            int currentDigit = num[i] - '0';

            // Remove current digit from the factors.
            A currentFactors = digitFactor(currentDigit);

            for (int j = 0; j < 4; j++) {
                prefixFactors[j] -= currentFactors[j];
            }


            // If there is already a zero before this position,
            // we cannot keep the prefix unchanged.
            //
            // Example:
            // 120...
            //
            // If we are changing a digit after the zero,
            // the zero would remain in the answer.
            if (i > firstZero)
                continue;


            // Try every larger digit.
            for (int bigger = currentDigit + 1;
                 bigger <= 9;
                 bigger++) {

                A biggerFactors = digitFactor(bigger);

                // Factors still needed after:
                //
                // prefix + bigger digit
                //
                A remaining = need;

                for (int j = 0; j < 4; j++) {

                    remaining[j] -= prefixFactors[j];
                    remaining[j] -= biggerFactors[j];

                    if (remaining[j] < 0)
                        remaining[j] = 0;
                }


                // How many digits are required for the remaining
                // factors?
                int required = digitsNeeded(remaining);

                // Number of positions available after i.
                int available =
                    (int)num.size() - i - 1;


                // Can we construct the suffix?
                if (required <= available) {

                    string answer;

                    // Keep original prefix.
                    answer += num.substr(0, i);

                    // Put the larger digit here.
                    answer += char('0' + bigger);

                    // Remaining unused positions should be 1,
                    // because 1 keeps the number as small as possible.
                    int ones = available - required;

                    answer += string(ones, '1');

                    // Add the digits required for divisibility.
                    answer += build(remaining);

                    return answer;
                }
            }
        }


        // --------------------------------------------------
        // 7. No solution with the same length.
        //
        // Therefore use n + 1 digits.
        // --------------------------------------------------

        int newLength = max((int)num.size() + 1, minDigits);

        int ones = newLength - minDigits;

        return string(ones, '1') + build(need);
    }
};