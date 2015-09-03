## Motivation

A popular way of input data is by storing it in a comma separated format.
It will be convenient if a class can use a csv parser via object composition. 
The CSV parser will be iterator based to minimize the implementation being exposed to the classes using it.

	For example I should be able to do this
```cpp 
		FileTable fileTable;
        // here possible issues are checked - duplicates,empty line,invalid number of values
		fileTable.init("sample.csv");

		void buildIndex(Table & table,int columnToBeIndexed, int columnToBeLookedUp) {
			for(tokens : table) {
				index.insert(tokens[columnToBeIndexed], tokens[columnToBeLookedUp]);
			}

		}
```

## Code design

The base class Table has the implementations of iterator functions. It requires two abstract classes to be implemented 
```cpp
    int getNumberOfRows() {

    std::vector<std::string> getRow(int index)
```
