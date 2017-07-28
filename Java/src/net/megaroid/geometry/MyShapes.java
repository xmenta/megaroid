package net.megaroid.geometry;

public class MyShapes {
	
	public static void main(String[] args) {
		
		Shape[] shapes = new Shape[] {
				new Rectangle(10, 5),
				new Square(7)
		};
		
		for (Shape s : shapes) {
			System.out.println("The size of '" + s + "' is " + s.getArea());
			s.draw();
		}
		
	}

}
