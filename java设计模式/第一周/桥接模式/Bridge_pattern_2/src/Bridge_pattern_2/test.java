package Bridge_pattern_2;

public class test {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		//��windows Java Text
		JavaLanguage jl = new JavaLanguage();
		TextForm tf = new TextForm();
		LoggerWindows wlogger = new LoggerWindows(tf,jl);
		wlogger.outputLog("��־1");
		
	}

}

