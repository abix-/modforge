// Address: 0x14028ab20
// Ghidra name: FUN_14028ab20
// ============ 0x14028ab20 FUN_14028ab20 (size=88) ============


void FUN_14028ab20(longlong param_1,int param_2)



{

  longlong lVar1;

  char cVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x18);

  FUN_140179b40(*(undefined8 *)(lVar1 + 0xb80));

  cVar2 = FUN_14028b370(lVar1,param_2);

  if (cVar2 != '\0') {

    *(undefined4 *)((longlong)param_2 * 0x98 + 0x68 + lVar1) = 0;

    *(undefined1 *)((longlong)param_2 * 0x98 + 0x9c + lVar1) = 0;

  }

  FUN_140179b60(*(undefined8 *)(lVar1 + 0xb80));

  return;

}




