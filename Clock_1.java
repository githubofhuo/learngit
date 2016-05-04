package Clock;

public class Clock_1 {
	public static class Display {
		private int value = 0;
		private int limit = 0;
		
		public Display(int limit) {
			this.limit = limit;
		}
		
		public int getValue() {
			return value;
		}
	
		public void increase() {
			value++;
			if(value == limit) {
				value = 0;
			}
		}
		
		public void increase(Display d) {
			value++;
			if(value == limit) {
				value = 0;
				d.increase();
			}
		}
		
		public static void main(String[] args) {
			Display d = new Display(24);
			for(;;) {
				d.increase();
				System.out.println(d.getValue());
			}
		}
	}
	
	public static class Clock {
		public Display minute = new Display(60);
		public Display hour = new Display(24);
		
		public void start() {
			while(true) {
				minute.increase(hour);
				System.out.printf("%02d:%02d\n",hour.getValue(), minute.getValue());
			}
		}
		
	public static void main(String[] args) {
		Clock clock = new Clock();
		clock.start();
	}
}

}
