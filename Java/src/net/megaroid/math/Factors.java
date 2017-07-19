package net.megaroid.math;

public class Factors {
	
	private int mNumber;
	
	public Factors(int number) {
		mNumber = number;
	}

	public int getNumber() {
		return mNumber;
	}
	
	public void printAllFactors() {
		System.out.print("Factors: ");
		int sqrtN = (int)Math.sqrt(mNumber);
		for (int i = 1; i <= sqrtN; i++) {
			if (mNumber % i == 0) {
				System.out.print(i + " ");
				if (i * i != mNumber) {
					System.out.print((mNumber / i) + " ");
				}
			}
		}
		System.out.println("");
	}
	
	public static void main(String[] args) {
		
		System.out.print("Input a number : ");

		java.util.Scanner scanner = new java.util.Scanner(System.in);
		int num = scanner.nextInt();
		scanner.close();
		
		Factors f = new Factors(num);
		System.out.println("The number is " + f.getNumber());
		
		f.printAllFactors();
	}
}
