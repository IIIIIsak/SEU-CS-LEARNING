#include "LR1State.h"
#include<cassert>


LR1State::LR1State(int state_ID):ParserState(state_ID)
{
}


LR1State::~LR1State()
{
}
void LR1State::calFollowSet(ProductionStack& p, set<ProductionStack>& fps)
{
	string name = p.get_head()->get_node_name();
	//����follow��, p�����state��ǰproductions �� ���е�production�������Լ���follow set,һ��Ҫע���ǵ�ǰstate�µ�production
	for (auto p_iter = fps.begin(); p_iter != fps.end(); p_iter++) {
		//������ǰfps�����еĲ���ʽ
		//ProductionStack& op = const_cast<ProductionStack&>(*p_iter);  //��set����������ǿ�иı�const����
		ProductionStack  op = *p_iter;
		Node* currentNode = op.get_head()->getNodeInProduction(op.get_production_id(), op.get_stackState());
		
		if (currentNode!=nullptr && currentNode->get_node_name() == p.get_head()->get_node_name()) {
			//�������ʽ�еķ��ս����ͬ������follow����
			//�ȼ������ʽ֮����ŵ�first����
			set<string>firstSetS = op.get_head()->calFirstSet(op.get_production_id(), op.get_stackState() + 1);
			auto none_iter = firstSetS.find("none");
			if (none_iter != firstSetS.end()|| firstSetS.size()==0) {
				//��first�����д��ڿմ��ߣ��ϲ�first��ԭ�����ʽ��follow
				//�Ȱ� noneȥ����
				if(firstSetS.size() != 0)
					firstSetS.erase(none_iter);
				//����follow����Ϊfirst��
				p.set_followSet(firstSetS);
				//�ϲ�first����follow
				p.insertFollowSets(op.get_followSet());
			}
			else {
				//����ֻΪ first���� ����first��û��none
				p.set_followSet(firstSetS);
			}
		}
	}
	
}
void LR1State::stateGrow(ProductionManager& pm)
{
	int id = stateID;
	// ״̬������������state���һ��state��չ��ֱ���޷�������չ
	while (true) {
		//ÿ����չ��ʹ�ͷ����
		bool processAgain = false;
		for (auto fp_iter = productions.begin(); fp_iter != productions.end(); fp_iter++) {
			//��ͷ��ʼ���ܷ�����µĲ���ʽ
			// ���ڵ�set��Ķ����Ѿ������
			ProductionStack& fp = const_cast<ProductionStack&>(*fp_iter);  //ǿת
			if (fp.get_isProcess() == false) {
				//����л�û�д���Ĳ���ʽ��������processAgainΪtrue��֪�����еĲ���ʽ���������ˣ�����whileѭ��
				processAgain = true;
			}
			else {
				continue;  //�����Ѿ�������ɵ�ʽ��
			}
			fp.set_isProcess(true);  //����Ѿ������������ʽ��
			Node* currentNode = fp.get_head()->getNodeInProduction(fp.get_production_id(), fp.get_stackState());
			if (currentNode == nullptr) {
				continue;    //���û�ҵ�֤��С���Ѿ�������ˡ�
			}
			if (dynamic_cast<NonTerminator*>(currentNode) != nullptr) {
				//����Ƿ��ս������Ҫ�����µĲ���ʽ
				vector<ProductionStack> newProductions = pm.generateProductionStacks(currentNode->get_node_name());
				set<ProductionStack> fps = set<ProductionStack>();
				fps.insert(fp);
				for (auto np_iter = newProductions.begin(); np_iter != newProductions.end(); np_iter++) {
					calFollowSet((*np_iter), fps);        //����follow����,ע������������ֱ�Ӷ�np_iter�����ݽ����޸�
					if (addProductionAsMerge((*np_iter))) {
						//�����²���ʽ��
						fp_iter = productions.begin();  //��ֹ��bug
					}
				}
			}
		}
		if (!processAgain) {
			break;
		}
	}
}
bool LR1State::operator==(const ParserState& p)const
{	
	return productions == p.get_productions();   //����״̬�Ƿ���ȵı�׼�����ǵĲ���ʽ�Ƿ���ͬ,���ܳ���
}
bool LR1State::operator<(const ParserState& p)const
{
	bool issmall;
	if (this->productions < p.get_productions()) {
		issmall = true;
	}
	else {
		issmall = false;
	}
	return issmall;
}
