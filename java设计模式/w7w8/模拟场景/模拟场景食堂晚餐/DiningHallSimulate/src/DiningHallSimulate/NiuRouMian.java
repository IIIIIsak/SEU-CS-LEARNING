package DiningHallSimulate;

public class NiuRouMian extends Food {

	public NiuRouMian(Double price, String name) {
		super(price, name);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public void accept(Visitor v) {
		// TODO �Զ����ɵķ������
		v.visit(this);
	}

}
