package Composite_Pattern_1;

public class test {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		FruitPlate fruitPlate = new FruitPlate();
		//���һЩˮ��
		int i=0;
		for (i =0;i<3;i++) {
			fruitPlate.add(new Apple());
		}
		for (i =0;i<2;i++) {
			fruitPlate.add(new Banana());
		}
		for (i =0;i<4;i++) {
			fruitPlate.add(new Peer());
		}
		
		//���һЩˮ��
		FruitPlate fruitPlate2 = new FruitPlate();
		

		for (i =0;i<1;i++) {
			fruitPlate2.add(new Apple());
		}
		for (i =0;i<3;i++) {
			fruitPlate2.add(new Banana());
		}
		for (i =0;i<2;i++) {
			fruitPlate2.add(new Peer());
		}
		fruitPlate.add(fruitPlate2);
		
		Child child = new Child(fruitPlate);
		child.eatFruit();
	}

}

