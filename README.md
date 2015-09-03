## Motivation


A lot of input is stored in a comma separated format inside a file. It will be convenient if any class can use a csv parser via object composition. the CSV parser will be iterator based to minimize the implementation exposed to the classes using it.

	For example I should be able to do this

		FileTable fileTable;
		fileTable.init("sample.csv"); // here possible issues are checked - duplicates,empty line,invalid number of values

		void buildIndex(Table & table,int columnToBeIndexed, int columnToBeLookedUp) {
			for(tokens : table) {
				index.insert(tokens[columnToBeIndexed], tokens[columnToBeLookedUp]);
			}

		}
