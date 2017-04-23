#include <ntddk.h>

VOID mDriverUnload(PDRIVER_OBJECT pDriverObject)
{
	KdPrint(("driver unload!\r\n"));
}

VOID string( VOID );

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING regPath)
{
	KdPrint(("driver entry!\r\n"));
	pDriverObject->DriverUnload = mDriverUnload;
	
	string();
	return STATUS_SUCCESS;
}

VOID string( VOID )
{
	WCHAR dst_buf[512] = {0};
	UNICODE_STRING dst;
	NTSTATUS status;
	UNICODE_STRING file_path = RTL_CONSTANT_STRING(L"\\??\\C:\\winddk\\7600.16385.1\\inc\\cifs.h");
	USHORT file_size = 1024;
	
	KdPrint(("file path = %wZ, file size = %d \r\n", &file_path, file_size));
	// ×Ö·û´®³õÊ¼»¯
	RtlInitEmptyUnicodeString(&dst, dst_buf, sizeof(WCHAR) * 512);
	
	
	
	KdPrint(("file_path.length = %d\r\n",file_path.Length));
	
	dst.Length = wcslen(dst.Buffer) * sizeof(WCHAR);
	
	KdPrint(("dst.length = %d\r\n", dst.Length));
	
}