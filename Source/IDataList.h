#pragma once

template<typename T>
class IDataList
{
public:
	IDataList() {}
	virtual ~IDataList() {}

	virtual T GetAndRemove() = 0;

	virtual void Add(const T _element) = 0;

	virtual bool Empty() = 0;
};
