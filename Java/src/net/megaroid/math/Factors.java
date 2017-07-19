package net.megaroid.math;

import java.util.Scanner;

public class Factors {
	
	private int mNumber;
	private int[] mFactors; 
	private int mCount;
	
	public Factors(int number) {
		mNumber = number;
	}

	public int getNumber() {
		return mNumber;
	}
	
	public void printAllFactors() {
		if (mFactors == null) {
			initialize();
		}
		
		System.out.print("Factors: ");
		for (int i = 0; i < mCount; i++) {
			System.out.print(mFactors[i] + " ");;
		}
		System.out.println("");
 	}
	
	private void initialize()
	{
		int sqrtN = (int)Math.sqrt(mNumber);
		mCount = 0;
		
		mFactors = new int[sqrtN * 2];
		
		for (int i = 1; i <= sqrtN; i++) {
			if (mNumber % i == 0) {
				mFactors[mCount++] = i;
				if (i * i != mNumber) {
					mFactors[mCount++] = mNumber / i;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		
		System.out.print("Input a number : ");

		Scanner scanner = new Scanner(System.in);
		int num = scanner.nextInt();
		scanner.close();
		
		Factors f = new Factors(num);
		System.out.println("The number is " + f.getNumber());
		
		f.printAllFactors();
	}
}
