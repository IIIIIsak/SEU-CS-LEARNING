package HWCompany_simulate;

public abstract class CampusRecruit implements Recruit {
	//���� ְ����ģʽ��У԰��Ƹ��
	private CampusRecruit nextRecruit;

	public CampusRecruit getNextRecruit() {
		return nextRecruit;
	}

	public void setNextRecruit(CampusRecruit nextRecruit) {
		this.nextRecruit = nextRecruit;
	}
}
