package Composite_Pattern_2;

public abstract class AntiComponent {
	public  void add(AntiComponent c) {
		System.out.println("��ӳ���������");
	}
	public void remove(AntiComponent c) {
		System.out.println("ɾ������������");
	}
	public AntiComponent findChild(int index) {
		System.out.println("ɾ������������");
		return null;
	}
	public abstract void scan();
}

