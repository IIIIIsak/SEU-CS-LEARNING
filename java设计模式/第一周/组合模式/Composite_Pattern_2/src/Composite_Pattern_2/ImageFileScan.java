package Composite_Pattern_2;

public class ImageFileScan extends AntiComponent {

	String fileName;
	public ImageFileScan(String f) {
		// TODO �Զ����ɵĹ��캯�����
		this.fileName = f;
	}
	@Override
	public void scan() {
		// TODO �Զ����ɵķ������
		System.out.println("ɨ����ͼƬ: "+this.fileName);
	}

}

