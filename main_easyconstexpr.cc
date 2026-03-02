#include "hashtable/easyset.h"
#include "hashtable/easymap.h"

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
	myhashtable::EasySet<std::string_view, 16, 64, myhashtable::ArrayStorage, DJBHash> ht{};

	ht.insert("Niki"	);
	ht.insert("Ivan"	);
	ht.insert("Stoyan"	);
	ht.insert("Peter"	);

	return ht.exists("Peter") ? 400 : 0;
}

constexpr int map_constexpr(){
	myhashtable::EasyMap<std::string_view, int, 16, 64, myhashtable::ArrayStorage, DJBHash> ht{};

	ht.insert("Niki"	, 100 );
	ht.insert("Ivan"	, 200 );
	ht.insert("Stoyan"	, 300 );
	ht.insert("Peter"	, 400 );

	return *ht.find("Peter");
}

static_assert(set_constexpr() == 400);
static_assert(map_constexpr() == 400);

int main(){
}

