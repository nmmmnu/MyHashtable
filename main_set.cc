#include "hashtable/hashtable.h"
#include "hashtable/set.h"
#include "hashtable/compactstorage.h"

#include <iostream>
#include <string_view>
#include <limits>



template<typename HT, typename T>
constexpr auto yn(HT const &ht, T const &key){
	return exists(ht, key) ? "Y" : "N";
};

template<typename T, size_t Items, size_t Size>
using MyStorage = myhashtable::CompactStorage<T, Items, Size>;

int main(){
	if constexpr(1){
		myhashtable::Set<std::string_view, 16, 64, MyStorage> ht;

		insert(ht, "Niki"	);
		insert(ht, "Ivan"	);
		insert(ht, "Stoyan"	);
		insert(ht, "Peter"	);

		// can not compile:
		// *findMut(ht, "Niki") = 111;

		std::cout << yn(ht, "Niki"		) << '\n';
		std::cout << yn(ht, "Ivan"		) << '\n';
		std::cout << yn(ht, "Stoyan"		) << '\n';
		std::cout << yn(ht, "Peter"		) << '\n';

		std::cout << yn(ht, "None"		) << '\n';

		ht.stats();
	}

	if constexpr(1){
		myhashtable::Set<int, 16, 64, MyStorage> ht; // { std::numeric_limits<int>::max() };

		insert(ht, 100 );
		insert(ht, 200 );
		insert(ht, 300 );
		insert(ht, 400 );

		// can not compile:
		// *findMut(ht, 100) = 111;

		std::cout << yn(ht, 100) << '\n';
		std::cout << yn(ht, 200) << '\n';
		std::cout << yn(ht, 300) << '\n';
		std::cout << yn(ht, 400) << '\n';

		std::cout << yn(ht, 999) << '\n';

		ht.stats();
	}
}


