package Bridge_pattern_1;

public class test {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		//���� 
		//�� windows �ϲ��� mp4�ļ�
		MP4File mp4File = new MP4File();
		WindowsPlayer windowsPlayer = new WindowsPlayer();
		windowsPlayer.setVedioFile( mp4File);
		windowsPlayer.play("��Ƶ1");
		
		//�����Ҫ����һ�� ƽ̨ ��һ�ֲ��Ÿ�ʽ ֻ��Ҫ����һ���µ���ʵ�� VedioFile�ӿڣ� 
		//�½�һ����̳�VedioPlayer�࣬����Ҫ�ı�Դ����
		FLVFile flvFile = new FLVFile();
		MacintoshPlayer mPlayer  = new MacintoshPlayer();
		mPlayer.setVedioFile( flvFile );
		mPlayer.play("��Ƶ2");
	}

}
