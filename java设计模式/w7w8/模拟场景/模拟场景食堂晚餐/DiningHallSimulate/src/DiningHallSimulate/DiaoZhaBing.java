package DiningHallSimulate;

public class DiaoZhaBing extends Food {

	public DiaoZhaBing(Double price, String name) {
		super(price, name);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public void accept(Visitor v) {
		// TODO �Զ����ɵķ������
		v.visit(this);
	}

}
