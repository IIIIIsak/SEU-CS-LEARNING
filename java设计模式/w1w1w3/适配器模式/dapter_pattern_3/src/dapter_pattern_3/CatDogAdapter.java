package dapter_pattern_3;

public class CatDogAdapter implements CatBehavior, DogBehavior {
	CatBehavior cat;
	public void setCat(CatBehavior cat) {
		this.cat = cat;
	}

	public void setDog(DogBehavior dog) {
		this.dog = dog;
	}

	DogBehavior dog;
	
	public CatDogAdapter(CatBehavior c,DogBehavior d) {
		// TODO �Զ����ɵĹ��캯�����
		this.cat = c;
		this.dog = d;
	}

	@Override
	public void wang() {
		// TODO �Զ����ɵķ������
		this.cat.catchMouse();
	}

	@Override
	public void catchMouse() {
		// TODO �Զ����ɵķ������
		this.dog.wang();
	}

}
