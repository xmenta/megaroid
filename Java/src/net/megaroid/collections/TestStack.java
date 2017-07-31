package net.megaroid.collections;

import java.util.Scanner;
import net.megaroid.math.Rational;

public class TestStack {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String cmd = "";
		Stack<Rational> stack = new Stack<>(); 
		
		System.out.println("Input a command('push', 'pop', 'print', 'quit')");
		
		while (!cmd.equals("quit")) {
			System.out.print("> ");
			cmd = scanner.next();
			
			if (cmd.equals("push")) {
				System.out.print("Input two numbers ( n / m ): ");
				int n = scanner.nextInt();
				int m = scanner.nextInt();
				stack.push(new Rational(n, m));
			} else if (cmd.equals("pop")) {
				Rational num = stack.pop();
				System.out.println("Pop a number: " + num);
			} else if (cmd.equals("print")) {
				System.out.println("STACK:" + stack);
			} else if (cmd.equals("quit")) {
				break;
			} else {
				System.err.println("Unknown command '" + cmd + "'");
			}
		}
		
		scanner.close();
	}
	
}
