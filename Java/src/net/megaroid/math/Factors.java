package net.megaroid.math;

import java.util.Scanner;
import java.util.LinkedList;

public class Factors {
	
	private int mNumber;
	private LinkedList<Integer> mFactors;
	
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
		for (int i : mFactors) {
			System.out.print(i + " ");
		}
		System.out.println("");
 	}
	
	private void initialize()
	{
		int sqrtN = (int)Math.sqrt(mNumber);
		
		mFactors = new LinkedList<Integer>();
		
		for (int i = 1; i <= sqrtN; i++) {
			if (mNumber % i == 0) {
				mFactors.add(i);
				if (i * i != mNumber) {
					mFactors.add(mNumber / i);
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
