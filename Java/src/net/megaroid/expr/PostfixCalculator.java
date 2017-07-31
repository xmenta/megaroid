package net.megaroid.expr;

import java.util.Scanner;
import net.megaroid.collections.Stack;
import net.megaroid.math.Rational;

public class PostfixCalculator {
	
	private Stack<Rational> stack = new Stack<>();
	
	private static boolean isOperator(char op) {
		return op == '+' || op == '-' || op == '*' || op == '/';
	}
	
	public void putTerm(String term) {
		if (Character.isDigit(term.charAt(0))) {
			int n = Integer.parseInt(term);
			stack.push(new Rational(n));
		} else if (isOperator(term.charAt(0))) {
			Rational r2 = stack.pop();
			Rational r1 = stack.pop();
			
			switch (term.charAt(0)) {
			case '+':
				stack.push(r1.add(r2));
				break;
			case '-':
				stack.push(r1.subtract(r2));
				break;
			case '*':
				stack.push(r1.multiply(r2));
				break;
			case '/':
				stack.push(r1.divide(r2));
			}
		}
	}
	
	public boolean isComplete() {
		return stack.size() == 1;
	}
	
	public Rational getAnswer() {
		return stack.pop();
	}
	
	public String toString() {
		return "Stack >> " + stack;
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Input a postfix expression. '.' or '=' for exit.\n> ");
		PostfixCalculator calc = new PostfixCalculator();
		String term;
		while (true) {
			term = scanner.next();
			if (term.charAt(0) == '.' || term.charAt(0) == '=') {
				break;
			}
			
			calc.putTerm(term);
			System.out.println(calc.toString());
		}
		scanner.close();
		
		if (!calc.isComplete()) {
			throw new RuntimeException("Invalid Postfix Expression");
		}
		
		System.out.println("The answer is " + calc.getAnswer());
	}
}
