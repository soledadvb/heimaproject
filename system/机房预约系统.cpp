#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "globalFile.h"
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

void managerMenu(Identity * &manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ�� תΪ����ָ��,���������������ӿ�
		Manager * man = (Manager*)manager;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��¼����	����1	�����ļ���	����2	�����������
void LoginIn(string fileName, int type)
{
	//����ָ��,����ָ���������
	Identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "���������ѧ��: " << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ����: " << endl;
		cin >> id;
	}

	cout << "�������û���: " << endl;
	cin >> name;

	cout << "����������: " << endl;
	cin >> pwd;
	if (type == 1)
	{
		//ѧ�������֤
		int fId;	//���ļ��л�ȡ��id��
		string fName;	//���ļ��л�ȡ������
		string fPwd;	//���ļ��л�ȡ����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�! " << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
			 	//����ѧ����ݵ��Ӳ˵�

				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName;
		string fPwd;

		while(ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�����
				managerMenu(person);


				return;
			}
		}
	}

	cout << "��֤��¼ʧ��!" << endl;
	system("pause");
	system("cls");

	return;

}

int main() {
	int select = 0; //���ڽ����û���ѡ��

	while (true)
	{
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select; // �����û�ѡ��

		switch (select)
		{
		case 1:  //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������,������ѡ��!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	

	system("pause");

	return 0;
}