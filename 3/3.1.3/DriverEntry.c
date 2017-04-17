#include <ntddk.h>

VOID mDirverUnload(PDRIVER_OBJECT pDriverObject)
{
	KdPrint(("driver unload!"));
}

VOID string(VOID);

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING regPath)
{
	KdPrint(("driver entry!"));
	pDriverObject->DriverUnload = mDirverUnload;
	string();
	return STATUS_SUCCESS;
}

VOID string(VOID)
{
	// 字符串的拷贝
	// 1.需要目标字符串的buffer有足够的缓冲区
	UNICODE_STRING dst;	// 目标字符串
	WCHAR dst_buf[256];	// 缓冲区域
	UNICODE_STRING src = RTL_CONSTANT_STRING(L"My source string! ");
	RtlInitEmptyUnicodeString(&dst, dst_buf, 256*sizeof(WCHAR));
	RtlCopyUnicodeString(&dst, &src);
	KdPrint(("%wZ",&dst));
}

/*
VOID
  RtlInitEmptyUnicodeString(
    IN OUT PUNICODE_STRING  DestinationString,
    IN PCWSTR  Buffer,
    IN USHORT  BufferSize
    ); 
Parameters
DestinationString
Pointer to the UNICODE_STRING structure to be initialized.
Buffer
Pointer to a caller-allocated buffer to be used to contain a WCHAR string.
BufferSize
Length, in bytes, of the buffer that Buffer points to.
Return Value
无
*/