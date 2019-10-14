package Bridge_pattern_2;

public class LoggerWindows extends Logger {

	
	public LoggerWindows(OutputFileForm o, CodeLanguage l){
		super(o,l);
	}
	@Override
	public void outputLog(String fileName) {
		// TODO �Զ����ɵķ������
		this.language.useLanguage(fileName);
		this.outputForm.outputForm(fileName);
		System.out.println("��Windowƽ̨����������־"+fileName);
	}

}
