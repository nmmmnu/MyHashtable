#ifndef MY_HASHTABLE_EASY_SET_H_
#define MY_HASHTABLE_EASY_SET_H_

#include "easyhashtable.h"
#include "set.h"

namespace myhashtable{

	template<typename K, size_t Size, template<typename,size_t> typename Storage = ArrayStorage, typename Hash = std::hash<K> >
	struct EasySet : EasyHashtable< Set<K, Size, Storage, Hash> >{

		using Controller = Set<K, Size, Storage, Hash>;

		template<typename... Ts>
		constexpr EasySet(Ts &&...ts) : EasyHashtable<Controller>(std::forward<Ts>(ts)...){}
	};

} // namespace myhashtable

#endif

