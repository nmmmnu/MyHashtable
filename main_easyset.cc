#include "hashtable/easyset.h"
#include "hashtable/compactstorage.h"

#include <iostream>
#include <string_view>
#include <limits>



template<typename HT, typename T>
constexpr auto eyn(HT const &ht, T const &key){
	return ht.exists(key) ? "Y" : "N";
};

template<typename T, size_t Items, size_t Size>
using MyStorage = myhashtable::CompactStorage<T, Items, Size>;

int main(){
	if constexpr(1){
		myhashtable::EasySet<std::string_view, 16, 64, MyStorage> ht;

		ht.insert("Niki"	);
		ht.insert("Ivan"	);
		ht.insert("Stoyan"	);
		ht.insert("Peter"	);

		std::cout << eyn(ht, "Niki"		) << '\n';
		std::cout << eyn(ht, "Ivan"		) << '\n';
		std::cout << eyn(ht, "Stoyan"		) << '\n';
		std::cout << eyn(ht, "Peter"		) << '\n';

		std::cout << eyn(ht, "None"		) << '\n';

		ht.stats();
	}

	if constexpr(1){
		myhashtable::EasySet<int, 16, 64, MyStorage> ht;

		ht.insert(100 );
		ht.insert(200 );
		ht.insert(300 );
		ht.insert(400 );

		std::cout << eyn(ht, 100) << '\n';
		std::cout << eyn(ht, 200) << '\n';
		std::cout << eyn(ht, 300) << '\n';
		std::cout << eyn(ht, 400) << '\n';

		std::cout << eyn(ht, 999) << '\n';

		ht.stats();
	}
}


