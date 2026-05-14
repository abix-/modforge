// Address: 0x14028a9f0
// Ghidra name: FUN_14028a9f0
// ============ 0x14028a9f0 FUN_14028a9f0 (size=138) ============


bool FUN_14028a9f0(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x18);

  FUN_140179b40(*(undefined8 *)(lVar1 + 0xb80));

  cVar2 = FUN_14028b370(lVar1,param_2);

  if (cVar2 == '\0') {

    FUN_140179b60(*(undefined8 *)(lVar1 + 0xb80));

    FUN_14012e850("Bad effect id");

    return false;

  }

  iVar3 = FUN_14028bf60();

  FUN_140179b60(*(undefined8 *)(lVar1 + 0xb80));

  return iVar3 == 0;

}




