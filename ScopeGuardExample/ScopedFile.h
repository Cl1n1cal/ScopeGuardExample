#include <fstream>

#include "IScopedFile.h"

#ifndef SCOPEDFILE_H
#define SCOPEDFILE_H

class ScopedFile : IScopedFile
{
public:
	//Delete default constructor. Prevents below example:
	//MyObj obj1;
	ScopedFile() = delete;

	//Parameterized constructor
	explicit ScopedFile(const char* filename, const char* mode);


	//Delete copy constructor. Prevents below example:
	//MyClass obj1(5); - Calls the constructor
	//MyClass obj2 = obj1 - Calls the copy constructor
	ScopedFile(const ScopedFile&) = delete;

	//Delete copy assignment constructor. Prevents below example:
	//MyClass obj1(5); - Calls the constructor
	//MyClass obj2(10); - Calls the constructor
	//obj2 = obj1; - Calls the copy assignment operator
	ScopedFile& operator=(const ScopedFile&) = delete;

	//Implement the move constructor and move assignment operator
	ScopedFile(ScopedFile&& other) noexcept;
	ScopedFile& operator=(ScopedFile&& other) noexcept;

	//Destructor
	~ScopedFile();

	//Implement the IScopedFile interface
	bool isOpen() override;
	void close() override;
	void write(const char* data) override;
	void write(const std::string& data) override;
private:
	std::FILE* file;
	std::string mode;
};

#endif
