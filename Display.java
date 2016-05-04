package display;

public class Display {
	private int value = 0;
	private int limit = 0;
	private static int step = 1;  /*static:¿‡±‰¡ø*/
	
	public Display(int limit) {
		this.limit = limit;
	}
	
	public void increase() {
		value++;
		if(value == limit) {
			value = 0;
		}
	}
	
	public int getValue() {
		return value;
	}
	
	public static void f()
	{
		step++;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Display d = new Display(24);
//		for(;;) {
//			d.increase();
//			System.out.println(d.getValue());
//		}
		Display d1 = new Display(10);
		Display d2 = new Display(20);
		d1.f();
		d1.increase();
		System.out.println(d1.getValue());
		System.out.println(d2.getValue());
		System.out.println(Display.step);
		System.out.println(Display.step);
		Display.step = 2;
		System.out.println(Display.step);
		System.out.println(Display.step);
		Display.step = 3;
		System.out.println(Display.step);
		System.out.println(Display.step);
	}

}
