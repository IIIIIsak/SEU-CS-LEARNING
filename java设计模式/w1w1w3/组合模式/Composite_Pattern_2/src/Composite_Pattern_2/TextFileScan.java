package Composite_Pattern_2;

public class TextFileScan extends AntiComponent {
	
	String fileName;
	public TextFileScan(String f) {
		// TODO �Զ����ɵĹ��캯�����
		this.fileName = f;
	}
	@Override
	public void scan() {
		// TODO �Զ����ɵķ������
		System.out.println("ɨ�����ı��ļ�: "+this.fileName);
	}

}

