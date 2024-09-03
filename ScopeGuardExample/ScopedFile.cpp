#include "ScopedFile.h"
#include <stdexcept>

//Parameterized constructor
ScopedFile::ScopedFile(const char* filename, const char* mode) {
	file = _fsopen(filename, mode, _SH_DENYNO);
	if (!file)
	{
		throw std::runtime_error("Failed to open file");
	}
}

//Destructor
ScopedFile::~ScopedFile()
{
	if (file)
	{
		(void) std::fclose(file);
	}
}

//Move constructor
ScopedFile::ScopedFile(ScopedFile&& other) noexcept : file(other.file)
{
	other.file = nullptr;
}

//Move assignment operator
ScopedFile& ScopedFile::operator=(ScopedFile&& other) noexcept
{
	if (this != &other)
	{
		if (file)
		{
			(void) std::fclose(file);
		}
		file = other.file;
		other.file = nullptr;
	}
	return *this;
}

bool ScopedFile::isOpen()
{
	return file != nullptr;
}

void ScopedFile::close()
{
	if (file)
	{
		(void) std::fclose(file);
		file = nullptr;
	}
}

void ScopedFile::write(const char* data) {
	if (!file) {
		throw std::runtime_error("File is not open for writing");
	}
	std::fwrite(data, sizeof(char), std::strlen(data), file);
}

void ScopedFile::write(const std::string& data) {
	write(data.c_str());
}


