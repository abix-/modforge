// Address: 0x14022b690
// Ghidra name: FUN_14022b690
// ============ 0x14022b690 FUN_14022b690 (size=107) ============


void FUN_14022b690(longlong param_1)



{

  longlong lVar1;

  BOOL BVar2;

  HHOOK pHVar3;

  HINSTANCE local_res8 [4];

  

  lVar1 = *(longlong *)(param_1 + 0x188);

  if (*(longlong *)(lVar1 + 0x48) == 0) {

    BVar2 = GetModuleHandleExW(6,(LPCWSTR)FUN_14018cd90,local_res8);

    if (BVar2 != 0) {

      BVar2 = GetKeyboardState((PBYTE)(*(longlong *)(lVar1 + 0xc0) + 0x288));

      if (BVar2 != 0) {

        pHVar3 = SetWindowsHookExW(0xd,FUN_14018cd90,local_res8[0],0);

        *(HHOOK *)(lVar1 + 0x48) = pHVar3;

      }

    }

  }

  return;

}




