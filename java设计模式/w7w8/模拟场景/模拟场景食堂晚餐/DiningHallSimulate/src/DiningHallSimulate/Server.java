package DiningHallSimulate;

public class Server implements Visitor {
	//ʳ�ù�����Ա��
	@Override
	public void visit(HangMenJi f) {
		// TODO �Զ����ɵķ������
		System.out.println("ʳ�ù�����Ա����"+f.getName());
	}

	@Override
	public void visit(DiaoZhaBing f) {
		// TODO �Զ����ɵķ������
		System.out.println("ʳ�ù�����Ա����"+f.getName());
	}

	@Override
	public void visit(NiuRouMian f) {
		// TODO �Զ����ɵķ������
		System.out.println("ʳ�ù�����Ա����"+f.getName());
	}

}
