package Observer_pattern;

public class Server implements CustomerListener {

	public void beScared() {
		System.out.println("�ͷ��ܵ�����");
	}

	@Override
	public void response() {
		// TODO �Զ����ɵķ������
		 this.beScared();
	}

}
