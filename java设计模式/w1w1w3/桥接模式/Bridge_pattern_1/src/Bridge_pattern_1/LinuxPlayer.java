package Bridge_pattern_1;

public class LinuxPlayer extends VedioPlayer {

	@Override
	public void play(String fileName) {
		// TODO �Զ����ɵķ������
		this.vedioFile.decode(fileName);
		System.out.println("��Linuxƽ̨����");
	}

}
