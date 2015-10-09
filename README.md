## Motivation

A popular way of input data is by storing it in a comma separated format.
It will be convenient if a class can use a csv parser via object composition.
The CSV parser will be iterator based to minimize the implementation being exposed to the classes using it.

```cpp
        void main() {
		        FileTable fileTable;
            PrimaryTreeIndex index;
		          fileTable.init("sample.csv");
              index.buildIndex(filetable, 0, 2);
        }

        class X {
		    void buildIndex(Table & table,int columnToBeIndexed, int columnToBeLookedUp) {
			    for(tokens : table) {
				    index.insert(tokens[columnToBeIndexed], tokens[columnToBeLookedUp]);
			    }

		    }
        }
```

## Code design

The base class Table covers the implementations of an iterator by overloading the C++ operators.
It does require two abstract class functions to be implemented

```cpp
    int getNumberOfRows() {

    std::vector<std::string> getRow(int index)
```
