package net.megaroid.collections;

public class IntStack {
	
	private int[] data = new int[100];
	private int count = 0;
	
	public void push(int value) {
		if (count >= 100) {
			throw new RuntimeException("Stack is full(Overflow)");
		}
		data[count++] = value;
	}
	
	public int pop() {
		if (count == 0) {
			throw new RuntimeException("Stack is empty(underflow)");
		}
		return data[--count];
	}
	
	public int top() {
		if (count == 0) {
			throw new RuntimeException("Stack is empty(underflow)");
		}
		return data[count - 1];
	}
	public int size() {
		return count;
	}
	
	public boolean isEmpty() {
		return count == 0;
	}

	public String toString() {
		String out = "[" + count + " elements] ";
		for (int i = 0; i < count; i++) {
			out += " " + data[i];
		}
		return out;
	}
}
