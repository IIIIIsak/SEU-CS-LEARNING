package Observer_pattern;

public class Guard implements CustomerListener {
	
	public void comeToSpot() {
		System.out.println("�����ϵ��ֳ�");
	}
	@Override
	public void response() {
		// TODO �Զ����ɵķ������
		this.comeToSpot();
	}

}
