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
	// �ַ����Ŀ���
	// 1.��ҪĿ���ַ�����buffer���㹻�Ļ�����
	UNICODE_STRING dst;	// Ŀ���ַ���
	WCHAR dst_buf[256];	// ��������
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
��
*/