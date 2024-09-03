#pragma once

#ifndef ISCOPEDHANDLE_H
#define ISCOPEDHANDLE_H

class IScopedHandle
{
public:

	virtual bool isOpen() = 0;
	virtual void close() = 0;

	virtual ~IScopedHandle() = default;
};


#endif
