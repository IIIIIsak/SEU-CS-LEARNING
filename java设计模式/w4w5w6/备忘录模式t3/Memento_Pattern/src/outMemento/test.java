package outMemento;

import Memento.Player;
import Memento.GameMemento;

public class test {
   
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
	    // client ����ʵ��
		Player p = new Player();
		GameSystem gs = new GameSystem();
		//����
		p.play("������������˴�Ͽ�ȵ���");
		p.printGameState();
	    //������Ϸ
		gs.setGameMemento(p.saveGame());
		
		//����
		p.play("������������֮��������׼����սboss");
		p.printGameState();
		//������Ϸ
		gs.setGameMemento(p.saveGame());
		
		//�������
		System.out.println("��������ˣ��ص�֮ǰ�����");
		
		//�ص�
		p.restartGame(gs.getGameMemento());
		p.printGameState();
		
	}

}


