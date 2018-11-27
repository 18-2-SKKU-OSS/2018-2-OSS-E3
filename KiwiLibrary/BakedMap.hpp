#pragma once

#include <map>
#include <algorithm>

#define USE_MIXED_VEC_MAP

#ifdef USE_UNORDERED_MAP
#include <unordered_map>

template<class Key, class Value>
class BakedMap : public std::unordered_map<Key, Value>
{
public:
	using std::unordered_map<Key, Value>::unordered_map;

	Value operator[](const Key& key) const
	{
		auto it = find(key);
		if (it == end()) return {};
		return it->second;
	}
};
#elif defined(USE_MIXED_VEC_MAP)

template<class Key, class Value>
class BakedMap
{
	typedef std::pair<const Key, Value> KVPair;
public:
	struct const_iterator
	{
		const KVPair* ptr = nullptr;
		uint32_t vecLength = 0; 
		Key cKey = 0;

		const_iterator(const KVPair* _ptr = nullptr, 
			uint32_t _vecLength = 0, Key _cKey = 0) 
			: ptr(_ptr), vecLength(_vecLength), cKey(_cKey)
		{
		}

		const_iterator operator++()
		{
			if (vecLength)
			{
				--vecLength;
				++cKey;
				ptr = (const KVPair*)((Value*)ptr + 1);
			}
			else
			{
				++ptr;
			}
			return *this;
		}

		bool operator==(const const_iterator& o) const
		{
			return ptr == o.ptr && vecLength == o.vecLength;
		}

		bool operator!=(const const_iterator& o) const
		{
			return !operator==(o);
		}

		KVPair operator*() const
		{
			if (vecLength) return std::make_pair(cKey, *(Value*)ptr);
			return *ptr;
		}
	};

protected:
	void* elems = nullptr;
	uint32_t vecLength = 0, length = 0;
	
	Value* getVec()
	{
		return (Value*)elems;
	}

	const Value* getVec() const
	{
		return (const Value*)elems;
	}

	std::pair<Key, Value>* getMap()
	{
		return (std::pair<Key, Value>*)((Value*)elems + vecLength);
	}

	const KVPair* getMap() const
	{
		return (const KVPair*)((const Value*)elems + vecLength);
	}

	template<class Input>
	std::pair<size_t, size_t> countVecSize(Input begin, Input end) const
	{
		size_t n = 0;
		Key last = {};
		for (; begin != end; ++begin, ++n)
		{
			if (begin->first >= 5 * n + 10) break;
			last = begin->first;
		}
		if (begin != end)
		{
			if (last % 2 == 0) ++last;
			if (begin->first < last) ++n;
		}
		return std::make_pair(n, last + 1);
	}
public:
	BakedMap() {}

	template<class Input>
	BakedMap(Input begin, Input end, bool useMixed) : length(std::distance(begin, end))
	{
		if (length)
		{
			auto vecInfo = countVecSize(begin, end);
			vecLength = vecInfo.second;
			length -= vecInfo.first;
			elems = operator new[](sizeof(Value) * vecLength + sizeof(std::pair<Key, Value>) * length);
			std::fill_n((Value*)elems, vecLength, Value{});

			for (size_t i = 0; begin != end; ++begin, ++i)
			{
				if (i < vecInfo.first) getVec()[begin->first] = begin->second;
				else getMap()[i - vecInfo.first] = *begin;
			}
		}
	}

	template<class Input>
	BakedMap(Input begin, Input end) : length(std::distance(begin, end))
	{
		if (length)
		{
			vecLength = 0;
			elems = operator new[](sizeof(std::pair<Key, Value>) * length);
			for (size_t i = 0; begin != end; ++begin, ++i)
			{
				getMap()[i] = *begin;
			}
		}
	}

	BakedMap(BakedMap&& o)
	{
		swap(o);
	}

	~BakedMap()
	{
		if (elems)
		{
			delete[] elems;
			elems = nullptr;
		}
	}

	BakedMap& operator= (BakedMap&& o)
	{
		swap(o);
		return *this;
	}

	void swap(BakedMap& o)
	{
		std::swap(o.elems, elems);
		std::swap(o.length, length);
		std::swap(o.vecLength, vecLength);
	}

	Value operator[](const Key& key) const
	{
		if (key < vecLength)
		{
			return getVec()[key];
		}
		auto ret = std::lower_bound(getMap(), getMap() + length, key, [](const std::pair<Key, Value>& p, const Key& k)
		{
			return p.first < k;
		});
		if (ret == getMap() + length)  return {};
		if (ret->first == key) return ret->second;
		return {};
	}

	size_t size() const
	{
		return vecLength + length;
	}

	const_iterator begin() const { return { (const KVPair*)getVec(), vecLength, 0 }; }
	const_iterator end() const { return { getMap() + length, 0, 0 }; }
};

#else
template<class Key, class Value>
class BakedMap
{
	typedef std::pair<const Key, Value>* iterator;
protected:
	std::pair<Key, Value>* elems = nullptr;
	size_t length = 0;
public:
	BakedMap() {}

	template<class Input>
	BakedMap(Input begin, Input end) : length(std::distance(begin, end))
	{
		if (length)
		{
			elems = new std::pair<Key, Value>[length];

			size_t i = 0;
			for (; begin != end; ++begin)
			{
				elems[i] = *begin;
				i++;
			}
		}
	}

	BakedMap(BakedMap&& o)
	{
		swap(o);
	}

	~BakedMap()
	{
		if (elems)
		{
			delete[] elems;
			elems = nullptr;
		}
	}

	BakedMap& operator= (BakedMap&& o)
	{
		swap(o);
		return *this;
	}

	void swap(BakedMap& o)
	{
		std::swap(o.elems, elems);
		std::swap(o.length, length);
	}

	Value operator[](const Key& key) const
	{
		auto ret = std::lower_bound(elems, elems + length, key, [](const std::pair<Key, Value>& p, const Key& k)
		{
			return p.first < k;
		});
		if (ret == elems + length) return {};
		if (ret->first == key) return ret->second;
		return {};
	}

	size_t size() const { return length; }

	iterator begin() { return (iterator)elems; }
	iterator end() { return (iterator)elems + length; }

	const iterator begin() const { return (iterator)elems; }
	const iterator end() const { return (iterator)elems + length; }
};


#endif
