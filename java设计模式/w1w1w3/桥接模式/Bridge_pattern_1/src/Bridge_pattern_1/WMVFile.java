package Bridge_pattern_1;

public class WMVFile implements VedioFile {

	@Override
	public void decode(String fileName) {
		// TODO �Զ����ɵķ������
		System.out.println("��"+fileName+".av�ļ����н���");
	}

}
