#include "ScopedHandle.h"

ScopedHandle::ScopedHandle(const HANDLE f_handle)
{
	f_handle_ = f_handle;
}

bool ScopedHandle::isOpen()
{
	if (f_handle_ == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	return f_handle_ != nullptr;
}

void ScopedHandle::close()
{
	CloseHandle(f_handle_);
}
