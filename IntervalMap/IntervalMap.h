#ifndef INTERVAL_MAP_H
#define INTERVAL_MAP_H

#include <memory>

template<typename TKey, typename TValue>
class IntervalMap {
public:
	IntervalMap(const TValue& val);
	IntervalMap(const IntervalMap& other);
	~IntervalMap();

	TValue& operator[](const TKey& key);
	void assign(const TKey& keyBegin, const TKey& keyEnd, const TValue& val);
	void print() const;

private:
	class IntervalMapImpl;
	std::unique_ptr<IntervalMapImpl> pImpl;
};

#endif // INTERVAL_MAP_H
