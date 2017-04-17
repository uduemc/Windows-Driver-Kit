#include <ntddk.h>

VOID mDriverUnload(PDRIVER_OBJECT pDriverObject)
{
	KdPrint(("driver unload!"));
	
}

VOID string(VOID);

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING regPath)
{
	KdPrint(("driver entry!"));
	pDriverObject->DriverUnload = mDriverUnload;
	string();
	return STATUS_SUCCESS;
}

VOID string(VOID)
{
	// 字符串的链接
	// 1.同样是要注意目标的缓冲区
	NTSTATUS status;
	UNICODE_STRING dst;
	WCHAR buffer[1024];
	UNICODE_STRING src = RTL_CONSTANT_STRING(L"My source string!");
	UNICODE_STRING src2 = RTL_CONSTANT_STRING(L" RtlAppendUnicodeStringToString!");
	
	RtlInitEmptyUnicodeString(&dst, buffer, 1024*sizeof(WCHAR));
	RtlCopyUnicodeString(&dst, &src);
	
	status = RtlAppendUnicodeToString(&dst, L"My second string!");
	if(!NT_SUCCESS(status)){
		KdPrint(("Error status: %X",status));
	}
	KdPrint(("dst: %wZ",&dst));
	
	
	status = RtlAppendUnicodeStringToString(&dst, &src2);
	if(!NT_SUCCESS(status)){
		KdPrint(("Error status: %X",status));
	}
	KdPrint(("dst: %wZ",&dst));
	
	
}