#include "manager.h"
//Ĭ�Ϲ���
Manager::Manager()
{
}
//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������ ��ȡ�������ļ��� ѧ�� ��ʦ��Ϣ
	this->initVector();
}
//�˵�����
void Manager::operMenu()
{
		cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
		cout << "\t\t ---------------------------------\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          1.����˺�            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          2.�鿴�˺�            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          3.�鿴����            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          4.���ԤԼ            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          0.ע����¼            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t ---------------------------------\n";
		cout << "��ѡ�����Ĳ����� " << endl;
}
//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	string fileName;
	string tip;
	string errorTip;

	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ�����:";
		errorTip = "ְ�����ظ�������������";
	}

	//����׷�ӵķ�ʽ д�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;			//ѧ�� ְ����
	string name;	//����
	string pwd;		//����

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << tip << endl;
	cin >> id;

	cout << "����������: " << endl;
	cin >> name;

	cout << "����������: " << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

}
//�鿴�˺�
void Manager::showPerson()
{

}
//�鿴������Ϣ
void Manager::showComputer()
{

}
//���ԤԼ��¼
void Manager::cleanFile() 
{

}

//��ʼ������
void Manager::initVector()
{
	//ȷ���������״̬
	vStu.clear();
	vTea.clear();

	//��ȡ��Ϣ ѧ��.��ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open());
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}

	cout << "��ǰѧ������Ϊ: " << vStu.size() << endl;
	ifs.close();

	//��ȡ��Ϣ	��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}

	cout << "��ǰ��ʦ����Ϊ: " << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			return true;
		}
	}
	return false;
}