package DiningHallSimulate;

public class AdvancedWindow extends WindowDecorator {

	public AdvancedWindow(Window w) {
		super(w);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public void process() {
		// TODO �Զ����ɵķ������
		System.out.println("����ǰ����ʾ���в�Ʒ��LED��Ļ");
		this.window.process();
	}

}
