package Adapter_pattern_1;

public class AdapterDogBird extends Robot {
	Bird bird;
	
	public void setBird(Bird bird) {
		this.bird = bird;
	}

	public void setDog(Dog dog) {
		this.dog = dog;
	}

	Dog dog;
	
	@Override
	public void cry() {
		// TODO �Զ����ɵķ������
		this.bird.birdCry();
	}

	@Override
	public void run() {
		// TODO �Զ����ɵķ������
		this.dog.run();
	}

}

