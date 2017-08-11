package net.megaroid.expr;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Tokenizer {
	
	private static  boolean isOperator(char c) {
		return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
	}

	public static List<String> parse(String text) {
		List<String> tokens = new LinkedList<>();
		
		int length = text.length();
		
		for (int i=0; i<length; i++) {
			
			if (Character.isWhitespace(text.charAt(i))) {
				continue;
			}
			if (isOperator(text.charAt(i))) {
				tokens.add(text.substring(i, i+1));
				continue;
			}
			if (Character.isDigit(text.charAt(i))) {
				int dotPos = -1;
				int nextPos = i+1;
				for (; nextPos < length; nextPos++) {
					if (text.charAt(nextPos) == '.') {
						if (dotPos >= 0) {
							throw new RuntimeException("Invalid number string :" + text.substring(i, nextPos + 1));
						}
						dotPos = nextPos;
					} else if (!Character.isDigit(text.charAt(nextPos))) {
						break;
					}
				}
				tokens.add(text.substring(i, nextPos));
				i = nextPos - 1;
				continue;
			}
			throw new RuntimeException("Unknown character '" + text.charAt(i));
		}
		return tokens;
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Input an expression. ('exit' for exit)");
		while (true) {
			System.out.print("> ");
			String expr = scanner.nextLine();
			if (expr.equals("exit")) {
				break;
			}
			
			try {
				List<String> tokens = Tokenizer.parse(expr);
				System.out.println("Tokens...");
				for (String token : tokens) {
					System.out.println("'" + token + "'");
				}
			} catch (Exception e) {
				System.err.println("An exception occurred : " + e.toString());
			}
		}
		scanner.close();
	}
}
