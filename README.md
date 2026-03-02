constexpr enabled, fast and extensible hashtable with open addressing
-
Idea:
-
Create hashtable on the stack with compile time decided size, add some items, then query them.
- C++17, can be easily downgraded to C++14 if you need.
- Can work fully constexpr - see **main_constexpr** and **main_easyconstexpr**.
- Can work as **Map**, **Set**.
- You can define additional custom Map-like interfaces.  See **hashtable/map.h**. 
- Have free function API or class API - see **main_XXX** vs **main_easyXXX**.
- Your custom Map-like interfaces can work with class API as well see **hashtable/easymap.h**. 

Operations:
-
- **insert** element. Supports overwrite. Guaranteed to be able to hold up to "compile time decided size" elements, even it made them in single long chain.
- **find** element. Returns pointer to the element. If element does not exists, returns **nullptr**
- **exists** - check element existence.
- **remove** - NOT SUPPORTED, because the table suppose to be read only for most of the time the program is running.

