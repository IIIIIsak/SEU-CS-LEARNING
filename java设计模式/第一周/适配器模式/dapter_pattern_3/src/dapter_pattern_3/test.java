package dapter_pattern_3;

public class test {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		Cat cat = new Cat();
		Dog dog = new Dog();
		CatDogAdapter adapter = new CatDogAdapter(cat,dog);
		adapter.catchMouse();   //è��һ����
		adapter.wang();         //����èһ��ץ����
	}

}

