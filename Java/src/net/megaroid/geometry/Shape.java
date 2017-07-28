package net.megaroid.geometry;

public abstract class Shape implements Drawable {
	
	private String name = "Unknown Shape";
	
	public Shape() {
	}
	
	public Shape(String name) {
		this.name = name;
	}
	
	public String toString() {
		return name;
	}
	
	public abstract int getArea();
	
	@Override
	public void draw()  {
		// Do nothing
	}
}
