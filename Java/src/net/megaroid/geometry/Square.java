package net.megaroid.geometry;

public class Square extends Rectangle {

	public Square(int length) {
		super(length, length);
	}
	
	public String toString() {
		return "Rectangle(" + width + " * " + width + ")";
	}
	
	@Override
	public int getArea() {
		return width * width;
	}
	
	@Override
	public void draw() {
		for (int h = 0; h < width; h++) {
			for (int w = 0; w < width; w++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
