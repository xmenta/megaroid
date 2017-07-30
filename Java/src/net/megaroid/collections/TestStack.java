package net.megaroid.collections;

import java.util.Scanner;

public class TestStack {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String cmd = "";
		IntStack stack = new IntStack();
		
		System.out.println("Input a command('push', 'pop', 'print', 'quit')");
		
		while (!cmd.equals("quit")) {
			System.out.print("> ");
			cmd = scanner.next();
			
			if (cmd.equals("push")) {
				System.out.print("Input a number: ");
				int num = scanner.nextInt();
				stack.push(num);
			} else if (cmd.equals("pop")) {
				int num = stack.pop();
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
