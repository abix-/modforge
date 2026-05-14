// Address: 0x140230120
// Ghidra name: FUN_140230120
// ============ 0x140230120 FUN_140230120 (size=104) ============


void FUN_140230120(longlong param_1,DWORD param_2)



{

  longlong lVar1;

  

  lVar1 = FUN_1402300c0();

  if (lVar1 == 0) {

    FUN_140138fb0(param_1 + 0x20,1);

    if ((int)param_2 < 0) {

      param_2 = 0xffffffff;

    }

    WaitForSingleObject(*(HANDLE *)(param_1 + 0x10),param_2);

    FUN_140138fb0(param_1 + 0x20,0xffffffff);

    FUN_1402300c0(param_1);

  }

  return;

}




