package Bridge_pattern_2;

public class TextForm implements OutputFileForm {

	@Override
	public void outputForm(String fileName) {
		// TODO �Զ����ɵķ������
		System.out.println("������־"+fileName+"�������ʽΪ.txt");
	}

}

