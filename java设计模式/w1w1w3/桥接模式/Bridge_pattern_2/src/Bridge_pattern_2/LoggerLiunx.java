package Bridge_pattern_2;

public class LoggerLiunx extends Logger {

	public LoggerLiunx(OutputFileForm o, CodeLanguage l) {
		super(o, l);
		// TODO �Զ����ɵĹ��캯�����
	}

	@Override
	public void outputLog(String fileName) {
		// TODO �Զ����ɵķ������
		this.language.useLanguage(fileName);
		this.outputForm.outputForm(fileName);
		System.out.println("��Windowƽ̨����������־"+fileName);
	}

}

