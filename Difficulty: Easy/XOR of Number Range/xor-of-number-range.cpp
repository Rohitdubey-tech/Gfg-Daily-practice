class Solution {
	private:
	int computeXOR(int n) {
		int rem = n%4;
		if (rem == 0)return n;
		else if (rem == 1)return 1;
		else if (rem == 2)return n + 1;
		else
			return 0;
	}
	public:
	int findXOR(int l, int r) {
		// code here
		int xorR = computeXOR(r);
		int xorLMinus1 = computeXOR(l - 1);
		return xorR^xorLMinus1;
	}
};