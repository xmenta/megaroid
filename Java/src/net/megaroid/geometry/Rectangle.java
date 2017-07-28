package net.megaroid.geometry;

public class Rectangle extends Shape {
	
	protected int width;
	protected int height;

	public Rectangle(int width, int height) {
		super("Rectangle");
		
		this.width = width;
		this.height = height;
	}
	
	public String toString() {
		return super.toString() + "(" + width + " x " + height + ")";
	}
	
	@Override
	public int getArea() {
		return width * height;
	}

	@Override
	public void draw() {
		for (int h = 0; h < height; h++) {
			for (int w = 0; w < width; w++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
