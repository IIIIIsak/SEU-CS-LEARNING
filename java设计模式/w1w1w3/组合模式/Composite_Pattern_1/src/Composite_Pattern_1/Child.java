package Composite_Pattern_1;

public class Child {
    //�ͻ�����
	FruitElement fruits;
	public void setFruits(FruitElement fruits) {
		this.fruits = fruits;
	}
	public Child(FruitElement f) {
		this.fruits = f;
	}
	public void eatFruit() {
		System.out.println("���ӿ�ʼ��ˮ������\n");
		this.fruits.eat();
	}
}
