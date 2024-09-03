#pragma once

#ifndef ISCOPEDFILE_H //Include guards prevent multiple includes of the same file
#define ISCOPEDFILE_H

class IScopedFile
{
public:

	//To check if a file is open
	virtual bool isOpen() = 0;

	//To close a file
	virtual void close() = 0;

	//Writing to a file
	virtual void write(const char* data) = 0;
	virtual void write(const std::string& data) = 0;

	//Virtual destructor
	virtual ~IScopedFile() = default;

};

#endif ISCOPEDFILE_H