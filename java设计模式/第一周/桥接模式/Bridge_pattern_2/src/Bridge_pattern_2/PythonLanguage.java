package Bridge_pattern_2;

public class PythonLanguage implements CodeLanguage {

	@Override
	public void useLanguage(String fileName) {
		// TODO �Զ����ɵķ������
		System.out.println("��־"+fileName+"ʹ��Python����");
	}

}
