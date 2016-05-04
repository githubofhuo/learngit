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
	void Add(int id);		//添加在列表头
private:
	int _id;
	Link *_pNext;
};

/*在起始时，列表为空而且指针初始化为零*/
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
