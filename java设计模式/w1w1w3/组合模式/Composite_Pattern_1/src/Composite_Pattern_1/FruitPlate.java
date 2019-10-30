package Composite_Pattern_1;

import java.util.ArrayList;

public class FruitPlate extends FruitElement {
	ArrayList<FruitElement> fruitElements = new ArrayList<FruitElement>();
	@Override
	public void add(FruitElement c) {
		// TODO �Զ����ɵķ������
		this.fruitElements.add(c);
	}

	@Override
	public void remove(FruitElement c) {
		// TODO �Զ����ɵķ������
		this.fruitElements.remove(c);
	}

	@Override
	public FruitElement getChild(int index) {
		// TODO �Զ����ɵķ������
		return this.fruitElements.get(index);
	}

	@Override
	public void eat() {
		// TODO �Զ����ɵķ������
		System.out.println("��ʼ�Թ������ˮ��");
		for(FruitElement f:this.fruitElements ) {
			f.eat();
		}
	}

}
