package net.megaroid.collections;

import java.util.List;
import java.util.LinkedList;

public class Stack<T> {
	
	private List<T> data = new LinkedList<T>();
	
	public void push(T value) {
		data.add(value);
	}
	
	public T pop() {
		if (data.isEmpty()) {
			throw new RuntimeException("Stack is empty(underflow)");
		}
		int lastIndex = data.size() - 1;
		T value = data.get(lastIndex);
		data.remove(lastIndex);
		return value;
	}
	
	public T top() {
		if (data.isEmpty()) {
			throw new RuntimeException("Stack is empty(underflow)");
		}
		return data.get(data.size() - 1);
	}
	
	public int size() {
		return data.size();
	}
	
	public boolean isEmpty() {
		return data.isEmpty();
	}

	public String toString() {
		String out = "[ Stack<" + this.getClass().getName() + "> " + data.size() + " elements ] ";
		for (T value : data) {
			out += " " + value;
		}
		return out;
	}
}
