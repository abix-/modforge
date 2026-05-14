// Address: 0x140223d00
// Ghidra name: FUN_140223d00
// ============ 0x140223d00 FUN_140223d00 (size=201) ============


void FUN_140223d00(longlong param_1,uint param_2,undefined8 param_3)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  lVar1 = (ulonglong)param_2 * 8;

  if (*(longlong *)(lVar1 + 0x1a8 + param_1) != 0) {

    FUN_1401841e0();

    *(undefined8 *)(lVar1 + 0x1a8 + param_1) = 0;

  }

  lVar2 = FUN_14012fd40(param_3);

  uVar3 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",param_3,lVar2 * 2 + 2);

  FUN_14012ee40(param_1 + 0x1a8 + lVar1,"%d %s",(*(int *)(param_1 + 0x204) + param_2) % 10,uVar3);

  FUN_1401841e0(uVar3);

  *(uint *)(param_1 + 0x1f8) = param_2 + 1;

  return;

}




