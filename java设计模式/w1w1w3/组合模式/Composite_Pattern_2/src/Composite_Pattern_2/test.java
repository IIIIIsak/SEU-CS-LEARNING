package Composite_Pattern_2;
public class test {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		// �����ļ���
		FolderScan folderscan = new FolderScan();
		// ���ͼƬ����Ƶ���ı�
		int i=0;
		for (i =0;i<3;i++) {
			folderscan .add(new TextFileScan("�ı�"+i+".txt"));
		}
		for (i =0;i<2;i++) {
			folderscan .add(new ImageFileScan("ͼƬ"+i+".txt"));
		}
		for (i =0;i<4;i++) {
			folderscan .add(new VedioFileScan("��Ƶ"+i+".txt"));
		}
		//������ļ��� 
		FolderScan folderscanSub = new FolderScan();
		for (i =0;i<5;i++) {
			folderscanSub.add(new TextFileScan("�ı�"+i+".txt"));
		}
		for (i =0;i<1;i++) {
			folderscanSub.add(new ImageFileScan("ͼƬ"+i+".txt"));
		}
		for (i =0;i<6;i++) {
			folderscanSub.add(new VedioFileScan("��Ƶ"+i+".txt"));
		}
		folderscan.add(folderscanSub);
		AntiVirus antiVirusSoftWare = new AntiVirus(folderscan);
		antiVirusSoftWare.scanVirus();
	}

}
