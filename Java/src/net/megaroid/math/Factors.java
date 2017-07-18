package net.megaroid.math;

public class Factors {
	
	private int mNumber;
	
	public Factors(int number) {
		mNumber = number;
	}

	public int getNumber() {
		return mNumber;
	}
	
	public static void main(String[] args) {
		
		Factors f = new Factors(10);
		System.out.println("The number is " + f.getNumber());
		
	}
}
