// Address: 0x14028ab80
// Ghidra name: FUN_14028ab80
// ============ 0x14028ab80 FUN_14028ab80 (size=109) ============


ulonglong FUN_14028ab80(longlong param_1,int param_2)



{

  byte bVar1;

  longlong lVar2;

  char cVar3;

  ulonglong uVar4;

  

  lVar2 = *(longlong *)(param_1 + 0x18);

  FUN_140179b40(*(undefined8 *)(lVar2 + 0xb80));

  cVar3 = FUN_14028b370(lVar2,param_2);

  if (cVar3 == '\0') {

    uVar4 = FUN_140179b60(*(undefined8 *)(lVar2 + 0xb80));

    return uVar4 & 0xffffffffffffff00;

  }

  bVar1 = *(byte *)((longlong)param_2 * 0x98 + 0x68 + lVar2);

  FUN_140179b60(*(undefined8 *)(lVar2 + 0xb80));

  return (ulonglong)(bVar1 & 1);

}




