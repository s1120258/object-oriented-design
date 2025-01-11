#include "IntervalMap.h"
#include <map>
#include <limits>
#include <string>
#include <iostream>

template<typename TKey, typename TValue>
class IntervalMap<TKey, TValue>::IntervalMapImpl {
public:
	IntervalMapImpl(const TValue& val) {
		m_map.insert(m_map.begin(), { std::numeric_limits<TKey>::min(), val });// map.insert(pos, {key, value})
	}

	IntervalMapImpl(const IntervalMapImpl& other) : m_map(other.m_map) {}

	TValue& operator[](const TKey& key) {
		return (--m_map.upper_bound(key))->second;
	}

	void assign(const TKey& keyBegin, const TKey& keyEnd, const TValue& val) {
		if (keyBegin >= keyEnd) return;

		auto itBegin = m_map.lower_bound(keyBegin);
		auto itEnd = m_map.lower_bound(keyEnd);
		TValue valEnd = std::prev(itEnd)->second;

		if (itBegin != m_map.begin() && std::prev(itBegin)->second == val) {
			--itBegin;
		} else {
			itBegin = m_map.insert(itBegin, { keyBegin, val });
			m_map.insert(itEnd, { keyEnd, valEnd });
		}

		if (itBegin != m_map.end() && itEnd != m_map.begin()) {
			m_map.erase(std::next(itBegin), std::prev(itEnd));
		}
	}

	void print() const {
		if (m_map.empty()) {
			std::cout << "Map is empty." << std::endl;
			return;
		}

		auto it = m_map.begin();
		while (it != m_map.end()) {
			std::cout << "[ " << it->first << ", ";
			std::cout << ((std::next(it) != m_map.end()) ? std::to_string(std::next(it)->first) : "inf");
			std::cout << " ] -> " << it->second << std::endl;
			++it;
		}
	}

private:
	std::map<TKey, TValue> m_map;
};

template<typename TKey, typename TValue>
IntervalMap<TKey, TValue>::IntervalMap(const TValue& val) : pImpl(std::make_unique<IntervalMapImpl>(val)) {}

template<typename TKey, typename TValue>
IntervalMap<TKey, TValue>::IntervalMap(const IntervalMap& other) : pImpl(std::make_unique<IntervalMapImpl>(*other.pImpl)) {}

template<typename TKey, typename TValue>
IntervalMap<TKey, TValue>::~IntervalMap() = default;

template<typename TKey, typename TValue>
TValue& IntervalMap<TKey, TValue>::operator[](const TKey& key) {
	return (*pImpl)[key];
}

template<typename TKey, typename TValue>
void IntervalMap<TKey, TValue>::assign(const TKey& keyBegin, const TKey& keyEnd, const TValue& val) {
	pImpl->assign(keyBegin, keyEnd, val);
}

template<typename TKey, typename TValue>
void IntervalMap<TKey, TValue>::print() const {
	pImpl->print();
}

// Explicit template instantiation
template class IntervalMap<int, int>;
template class IntervalMap<int, char>;
template class IntervalMap<int, std::string>;
