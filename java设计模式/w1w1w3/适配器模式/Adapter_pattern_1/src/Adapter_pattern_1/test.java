package Adapter_pattern_1;

public class test {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
        Dog dog = new Dog();
        Bird bird = new Bird();
        AdapterDogBird robot = new AdapterDogBird();
        robot.setBird(bird);
        robot.setDog(dog);
        Client client = new Client();
        client.setRobot(robot);
        client.active();
	}

}
