package outMemento;
// �� ����¼���ⶨ�� careTaker�� ��ֹ�ƻ���װ�ԣ�memento����ڲ���Աֻ�ܱ�Originator�����
import Memento.GameMemento;

public class GameSystem {
	private GameMemento gameMemento;

	public GameMemento getGameMemento() {
		return gameMemento;
	}

	public void setGameMemento(GameMemento gameMemento) {
		this.gameMemento = gameMemento;
	}



}
