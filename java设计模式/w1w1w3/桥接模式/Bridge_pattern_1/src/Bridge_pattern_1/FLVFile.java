package Bridge_pattern_1;

public class FLVFile implements VedioFile {

	@Override
	public void decode(String fileName) {
		// TODO �Զ����ɵķ������
		System.out.println("��"+fileName+".flv�ļ����н���");
	}

}
