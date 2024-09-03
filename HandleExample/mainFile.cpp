#include <iostream>
#include "ScopedHandle.h"
int main()
{
	std::cout << "Handling handles\n";

	ScopedHandle f_handle(CreateFile(L"test.txt", GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr));

	if (f_handle.isOpen())
	{
		std::cout << "Scoped handle created\n";
		getchar();
	}

	return 0;
}