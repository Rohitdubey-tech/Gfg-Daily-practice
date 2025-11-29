class Solution {
  public:
    int countSubs(string s) {
        struct State {
            int next[26];
            int link;
            int len;
            State() {
                len = 0;
                link = -1;
                for (int i = 0; i < 26; i++) next[i] = -1;
            }
        };

        int n = s.size();
        // Suffix automaton can have at most 2*n - 1 states
        vector<State> st(2 * n);
        int sz = 1;      // number of states
        int last = 0;    // index of state for whole string so far

        auto sa_extend = [&](char ch) {
            int c = ch - 'a';
            int cur = sz++;
            st[cur].len = st[last].len + 1;

            int p = last;
            // create transitions for c from all states that don't have it
            while (p != -1 && st[p].next[c] == -1) {
                st[p].next[c] = cur;
                p = st[p].link;
            }

            if (p == -1) {
                // no state to follow, link to root
                st[cur].link = 0;
            } else {
                int q = st[p].next[c];
                if (st[p].len + 1 == st[q].len) {
                    // direct parent is fine
                    st[cur].link = q;
                } else {
                    // need to clone state q
                    int clone = sz++;
                    st[clone] = st[q];           // copy transitions, len, link
                    st[clone].len = st[p].len + 1;

                    while (p != -1 && st[p].next[c] == q) {
                        st[p].next[c] = clone;
                        p = st[p].link;
                    }
                    st[q].link = st[cur].link = clone;
                }
            }
            last = cur;
        };

        // Build SAM
        for (char ch : s) {
            sa_extend(ch);
        }

        long long ans = 0;
        // state 0 is the initial state, skip it
        for (int i = 1; i < sz; i++) {
            ans += (st[i].len - st[st[i].link].len);
        }

        return (int)ans;   // GFG usually expects int
    }
};
