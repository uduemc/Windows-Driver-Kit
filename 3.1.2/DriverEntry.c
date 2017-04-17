#include <ntddk.h>

VOID mDriverUnload(PDRIVER_OBJECT pDriverObject)
{
	DbgPrint("DriverUnload");
}

VOID string(VOID)
{
	UNICODE_STRING str = {0};
	RtlInitUnicodeString(&str,L"This is a string!");
	
	DbgPrint("str: %wZ\n",&str);
}

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING regPath)
{
	DbgPrint("Driver start:");
	pDriverObject->DriverUnload = mDriverUnload;
	// ×Ö·û´®
	string();
	
	
	return STATUS_SUCCESS;
}