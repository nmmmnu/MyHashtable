#include "hashtable/easymap.h"
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
		myhashtable::EasyMap<std::string_view, std::string_view, 16, 64, MyStorage> ht;

		ht.insert("Niki"	, "Mihaylov"	);
		ht.insert("Ivan"	, "Petrov"	);
		ht.insert("Stoyan"	, "Georgiev"	);
		ht.insert("Peter"	, "Ivanov"	);

		*ht.find("Niki") = "Milev";

		std::cout << *ht.find("Niki"	) << '\n';
		std::cout << *ht.find("Ivan"	) << '\n';
		std::cout << *ht.find("Stoyan"	) << '\n';
		std::cout << *ht.find("Peter"	) << '\n';

		std::cout << eyn(ht, "none"	) << '\n';

		ht.stats();
	}

	if constexpr(1){
		myhashtable::EasyMap<std::string_view, std::string_view, 16, 64, MyStorage> ht;

		ht.insert({"Niki"	, "Mihaylov"	});
		ht.insert({"Ivan"	, "Petrov"	});
		ht.insert({"Stoyan"	, "Georgiev"	});
		ht.insert({"Peter"	, "Ivanov"	});

		*ht.find("Niki") = "Milev";

		std::cout << *ht.find("Niki"	) << '\n';
		std::cout << *ht.find("Ivan"	) << '\n';
		std::cout << *ht.find("Stoyan"	) << '\n';
		std::cout << *ht.find("Peter"	) << '\n';

		std::cout << eyn(ht, "none"	) << '\n';

		ht.stats();
	}

	if constexpr(1){
		myhashtable::EasyMap<std::string_view, int, 16, 64, MyStorage> ht;

		ht.insert("Niki"	, 100 );
		ht.insert("Ivan"	, 200 );
		ht.insert("Stoyan"	, 300 );
		ht.insert("Peter"	, 400 );

		*ht.find("Niki") = 111;

		std::cout << *ht.find("Niki"	) << '\n';
		std::cout << *ht.find("Ivan"	) << '\n';
		std::cout << *ht.find("Stoyan"	) << '\n';
		std::cout << *ht.find("Peter"	) << '\n';

		std::cout << eyn(ht, "none"	) << '\n';

		ht.stats();
	}

	if constexpr(1){
		myhashtable::EasyMap<int, std::string_view, 16, 64, MyStorage> ht;

		ht.insert(100, "Niki"		);
		ht.insert(200, "Ivan"		);
		ht.insert(300, "Stoyan"		);
		ht.insert(400, "Peter"		);

		*ht.find(100) = "Milev";

		std::cout << *ht.find(100) << '\n';
		std::cout << *ht.find(200) << '\n';
		std::cout << *ht.find(300) << '\n';
		std::cout << *ht.find(400) << '\n';

		std::cout << eyn(ht,  500) << '\n';

		ht.stats();
	}
}

