package net.megaroid.math;

/// The Greatest Common Denominator
public class GCD {
	public static int gcd(int m, int n) {
		int q;
		while (n > 0) {
			q = m % n;
			m = n;
			n = q;
		}
		return m;
	}
}
