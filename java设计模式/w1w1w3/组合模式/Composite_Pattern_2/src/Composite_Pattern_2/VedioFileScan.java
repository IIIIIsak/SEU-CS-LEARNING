package Composite_Pattern_2;

public class VedioFileScan extends AntiComponent {

	String fileName;
	public VedioFileScan(String f) {
		// TODO �Զ����ɵĹ��캯�����
		this.fileName = f;
	}
	@Override
	public void scan() {
		// TODO �Զ����ɵķ������
		System.out.println("ɨ������Ƶ�ļ�: "+this.fileName);
	}
}

