package net.megaroid.math;

public class Rational {
	
	private int n; // Numerator
	private int m; // Denominator, m must not be negative
	
	public Rational() {
		this(0, 1);
	}
	
	public Rational(int n) {
		this(n, 1);
	}
	
	public Rational(int n, int m) {
		if (m < 0) {
			m = -m;
			n = -n;
		}
		this.m = m;
		this.n = n;
	}
	
	public Rational(Rational r) {
		this.m = r.m;
		this.n = r.n;
	}
	
	public int getM() {
		return m;
	}
	
	public int getN() {
		return n;
	}
	
	public void reduce() {
		int signed = (n > 0) ? 1 : (n < 0) ? -1 : 0;
		n *= signed; 
		if (n > 1 && m > 1) {
			int gcd = GCD.gcd(m, n);
			if (gcd > 1) {
				m /= gcd;
				n /= gcd;
			}
		}
		n *= signed;
	}
	
	public Rational reduced() {
		Rational r = new Rational(this);
		r.reduce();
		return r;
	}

	public boolean equal(Rational r) {
		Rational r1 = this.reduced();
		Rational r2 = r.reduced();
		return r1.m == r2.m && r1.n == r2.n;
	}
	
	public Rational add(Rational r) {
		int gcd = GCD.gcd(m,  n);
		int m1 = m / gcd * r.m;
		int n1 = n * (m1 / m) + r.n * (m1 / r.m);
		Rational r1 = new Rational(n1, m1);
		return r1.reduced();
	}
	
	public Rational subtract(Rational r) {
		int gcd = GCD.gcd(m,  n);
		int m1 = m / gcd * r.m;
		int n1 = n * (m1 / m) - r.n * (m1 / r.m);
		Rational r1 = new Rational(n1, m1);
		r1.reduce();
		return r1;
	}
	
	public Rational multiply(Rational r) {
		Rational r1 = new Rational(n * r.n, m * r.m);
		r1.reduce();
		return r1;
	}
	
	public Rational divide(Rational r) {
		Rational r1 = new Rational(n * r.m, m * r.n);
		r1.reduce();
		return r1;
	}
	
	public String toString() {
		if (m == 1) {
			return Integer.toString(n);
		} 
		return "(" + n + "/" + m + ")";
	}
	
	public static void main(String[] args) {
		Rational r1 = new Rational(1, 4);
		Rational r2 = new Rational(1, 3);
		
		System.out.println(r1 + " + " + r2 + " = " + (r1.add(r2)));
		System.out.println(r1 + " - " + r2 + " = " + (r1.subtract(r2)));
		System.out.println(r1 + " * " + r2 + " = " + (r1.multiply(r2)));
		System.out.println(r1 + " / " + r2 + " = " + (r1.divide(r2)));
	}
}
