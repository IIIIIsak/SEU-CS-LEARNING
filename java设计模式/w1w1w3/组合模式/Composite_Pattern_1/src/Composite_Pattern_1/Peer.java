package Composite_Pattern_1;

public class Peer extends FruitElement {

	@Override
	public void add(FruitElement c) {
		// TODO �Զ����ɵķ������
		System.out.println("��ӳ��ִ���");
	}

	@Override
	public void remove(FruitElement c) {
		// TODO �Զ����ɵķ������
		System.out.println("ɾ�����ִ���");
	}

	@Override
	public FruitElement getChild(int index) {
		// TODO �Զ����ɵķ������
		System.out.println("��ȡ�ӽڵ���ִ���");
		return null;
	}

	@Override
	public void eat() {
		// TODO �Զ����ɵķ������
		System.out.println("����һ����");

	}

}
