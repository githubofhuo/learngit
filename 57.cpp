#pragma once
class Link
{
puclic:
	Link(Link* pNext, int id)
		: _pNext(pNext), _id(id) {}
	Link * Next() const
	{
		return _pNext;
	}
	int Id() const
	{
	return _id;
	}
	void Add(int id);		//������б�ͷ
private:
	int _id;
	Link *_pNext;
};

/*����ʼʱ���б�Ϊ�ն���ָ���ʼ��Ϊ��*/
class List
{
public:
	List(): _pHead(0) {}
	~List();
	void Add(int id);
	Link const * GetHead() const
	{
		return _pHead;
	}
private:
	Link* _pHead;
};
