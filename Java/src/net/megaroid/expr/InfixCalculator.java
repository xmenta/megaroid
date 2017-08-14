package net.megaroid.expr;

import java.util.List;
import java.util.Scanner;
import net.megaroid.math.Rational;

public class InfixCalculator {

	Rational compute(String expr) {
		List<String> tokens = Tokenizer.parse(expr);
		
		InfixToPostfix itp = new InfixToPostfix();
		for (String token : tokens) {
			itp.addTerm(token);
		}
		itp.finish();
		
		List<String> terms = itp.getPostfixTerms();
		PostfixCalculator pc = new PostfixCalculator();
		for (String term : terms) {
			pc.putTerm(term);
		}
		
		return pc.getAnswer();
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		InfixCalculator calc = new InfixCalculator();
		String expr;
		System.out.println("Input an expression, 'exit' for exit.\n");
		while (true) {
			System.out.print("> ");
			expr = scanner.nextLine();
			
			if (expr.trim().isEmpty()) {
				continue;
			}
			
			if (expr.equals("exit")) {
				break;
			}
			try {
				Rational result = calc.compute(expr);
				System.out.println("The result is " + result);
			} catch (Exception ex) {
				System.err.println("Exception : " + ex.toString());
			}
		}
		scanner.close();
	}

}
