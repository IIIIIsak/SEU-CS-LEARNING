package Bridge_pattern_1;

public class MP4File implements VedioFile {

	@Override
	public void decode(String fileName) {
		// TODO �Զ����ɵķ������
		System.out.println("��"+fileName+".mp4�ļ����н���");
	}

}
