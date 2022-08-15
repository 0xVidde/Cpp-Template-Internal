#include <windows.h>
#include <TlHelp32.h>
#include <vector>

namespace Utilities
{
	// Thank you GuidedHacking :kiss:
	void Patch(BYTE* dst, BYTE* src, unsigned int size);
	void PatchEx(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProcess);

	void Nop(BYTE* dst, unsigned int size);
	void NopEx(BYTE* dst, unsigned int size, HANDLE hProcess);

	uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<unsigned int> offsets);
	uintptr_t FindDMAAddyEx(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);
	// ------------------------------

	DWORD GetProcId(const wchar_t* procName);
	HANDLE GetProcHandle(const wchar_t* procName);
	uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName);

	DWORD AllocateConsole();
}
