package net.megaroid.math;

import java.util.Scanner;

public class Primes {
	
	public boolean isPrime(int n) {
		int sqrtN = (int)Math.sqrt(n);
		for (int i = 2; i <= sqrtN; i++) {
			if (n % 2 == 0) {
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n;
		
		while (true) {
			System.out.print("Input a number ( 0 or negative for exit ) :");
			n = scanner.nextInt();
			if (n <= 0) {
				break;
			}
			
			Primes primes = new Primes();
			System.out.println(n + " is a prime number ? " + primes.isPrime(n)); 
		}
		
		scanner.close();
	}
	
}
