#pragma once

#ifndef SCOPEDHANDLE_H
#define SCOPEDHANLDE_H
#include "IScopedHandle.h"
#include <Windows.h>

class ScopedHandle : IScopedHandle
{
public:
	explicit ScopedHandle(const HANDLE f_handle);

	//Delete copy constructors
	ScopedHandle(const ScopedHandle&) = delete;
	ScopedHandle& operator=(const ScopedHandle&) = delete;

	bool isOpen() override;
	void close() override;

private:
	HANDLE f_handle_;
};

#endif
