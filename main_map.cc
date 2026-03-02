#include "hashtable/hashtable.h"
#include "hashtable/map.h"
#include "hashtable/compactstorage.h"

#include <iostream>
#include <string_view>
#include <limits>



template<typename HT, typename T>
constexpr auto yn(HT const &ht, T const &key){
	return exists(ht, key) ? "Y" : "N";
};

template<typename T, size_t Size>
using MyStorage = myhashtable::CompactStorage<T,Size>;

int main(){
	if constexpr(1){
		myhashtable::Map<std::string_view, std::string_view, 64, MyStorage> ht;

		insert(ht, "Niki"	, "Mihaylov"	);
		insert(ht, "Ivan"	, "Petrov"	);
		insert(ht, "Stoyan"	, "Georgiev"	);
		insert(ht, "Peter"	, "Ivanov"	);

		std::cout << *find(ht, "Niki"	) << '\n';
		std::cout << *find(ht, "Ivan"	) << '\n';
		std::cout << *find(ht, "Stoyan"	) << '\n';
		std::cout << *find(ht, "Peter"	) << '\n';

		std::cout <<    yn(ht, "none"	) << '\n';

		ht.stats();
	}

	if constexpr(1){
		myhashtable::Map<std::string_view, std::string_view, 64, MyStorage> ht;

		insert(ht, {"Niki"	, "Mihaylov"	});
		insert(ht, {"Ivan"	, "Petrov"	});
		insert(ht, {"Stoyan"	, "Georgiev"	});
		insert(ht, {"Peter"	, "Ivanov"	});

		std::cout << *find(ht, "Niki"	) << '\n';
		std::cout << *find(ht, "Ivan"	) << '\n';
		std::cout << *find(ht, "Stoyan"	) << '\n';
		std::cout << *find(ht, "Peter"	) << '\n';

		std::cout <<    yn(ht, "none"	) << '\n';

		ht.stats();
	}

	if constexpr(1){
		myhashtable::Map<std::string_view, int, 64, MyStorage> ht;

		insert(ht, "Niki"	, 100 );
		insert(ht, "Ivan"	, 200 );
		insert(ht, "Stoyan"	, 300 );
		insert(ht, "Peter"	, 400 );

		std::cout << *find(ht, "Niki"	) << '\n';
		std::cout << *find(ht, "Ivan"	) << '\n';
		std::cout << *find(ht, "Stoyan"	) << '\n';
		std::cout << *find(ht, "Peter"	) << '\n';

		std::cout <<    yn(ht, "none"	) << '\n';

		ht.stats();
	}

	if constexpr(1){
		myhashtable::Map<int, std::string_view, 64, MyStorage> ht; // { std::numeric_limits<int>::max() };

		insert(ht, 100, "Niki"		);
		insert(ht, 200, "Ivan"		);
		insert(ht, 300, "Stoyan"	);
		insert(ht, 400, "Peter"		);

		std::cout << *find(ht, 100) << '\n';
		std::cout << *find(ht, 200) << '\n';
		std::cout << *find(ht, 300) << '\n';
		std::cout << *find(ht, 400) << '\n';

		std::cout <<    yn(ht, 500) << '\n';

		ht.stats();
	}
}

