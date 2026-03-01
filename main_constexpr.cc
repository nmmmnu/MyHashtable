#include "hashtable/hashtable.h"
#include "hashtable/set.h"
#include "hashtable/map.h"
// #include "hashtable/compactstorage.h"

#include <string_view>

struct DJBHash{
	constexpr size_t operator()(std::string_view s) const{
		size_t hash = 5381;
		for (char c : s)
			hash = ((hash << 5) + hash) + static_cast<unsigned char>(c);

		return hash;
	}
};

constexpr int set_constexpr(){
	myhashtable::Set<std::string_view, 64, myhashtable::ArrayStorage, DJBHash> ht{};

	insert(ht, "Niki"	);
	insert(ht, "Ivan"	);
	insert(ht, "Stoyan"	);
	insert(ht, "Peter"	);

	return exists(ht, "Peter") ? 400 : 0;
}

constexpr int map_constexpr(){
	myhashtable::Map<std::string_view, int, 64, myhashtable::ArrayStorage, DJBHash> ht{};

	insert(ht, "Niki"	, 100 );
	insert(ht, "Ivan"	, 200 );
	insert(ht, "Stoyan"	, 300 );
	insert(ht, "Peter"	, 400 );

	return *find(ht, "Peter");
}

static_assert(set_constexpr() == 400);
static_assert(map_constexpr() == 400);

int main(){
}

