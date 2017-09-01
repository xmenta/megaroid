package net.megaroid.expr;

import java.util.List;
import java.util.LinkedList;
import java.util.Scanner;
import net.megaroid.collections.Stack;

public class InfixToPostfix {

	Stack<Character> opStack = new Stack<>();
	List<String> terms = new LinkedList<>();

	public void addTerm(String term) {
		if (Character.isDigit(term.charAt(0))) {
			terms.add(term);
		} else if (term.charAt(0) == '(') {
			opStack.push('(');
		} else if (term.charAt(0) == ')') {
			while (true) {
				char op = opStack.pop();
				if (op == '(') {
					break;
				}
				terms.add(Character.toString(op));
			}
		} else if (isOperator(term.charAt(0))) {
			while (!opStack.isEmpty()) {
				char op = opStack.top();
				if (!isOperator(op)) {
					break;
				}
				if (getPriority(op) >= getPriority(term.charAt(0))) {
					opStack.pop();
					terms.add(Character.toString(op));
				}
				break;
			}
			opStack.push(term.charAt(0));
		}
	}
	
	public void finish() {
		while (!opStack.isEmpty()) {
			terms.add(Character.toString(opStack.pop()));
		}
	}
	
	public List<String> getPostfixTerms() {
		return terms;
	}
	
	private static boolean isOperator(char c) {
		return c == '+' || c == '-' || c == '*' || c == '/';
	}
	
	private static int getPriority(char c) {
		if (c == '+' || c == '-') {
			return 1;
		} else if (c == '*' || c == '/') {
			return 2;
		}
		return 0;
	}
	
	public static void main(String[] args) {
		String term;
		Scanner scanner = new Scanner(System.in);
		InfixToPostfix itp = new InfixToPostfix();
		
		System.out.print("Input a infix expression. ( '=' or '.' for exit) \n\n> ");
		
		while (true) {
			term = scanner.next();
			if (term.charAt(0) == '=' || term.charAt(0) == '.') {
				break;
			}
			itp.addTerm(term);
		}
		itp.finish();
		scanner.close();
		
		List<String> terms = itp.getPostfixTerms();
		System.out.print("Postfix Terms: "); 
		for (String t : terms) {
			System.out.print(" " + t);
		}
		System.out.println();
	}
}
