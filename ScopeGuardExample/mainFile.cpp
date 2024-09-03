#include <iostream>
#include "ScopedFile.h"

void WriteFile(const char* filename, const char* data)
{
	ScopedFile file(filename, "w");
	file.write(data);
}

int main()
{
	WriteFile("test.txt", "Hello World!");
	return 0;
}