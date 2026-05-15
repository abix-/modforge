// Address: 0x1401c5690
// Ghidra name: FUN_1401c5690
// ============ 0x1401c5690 FUN_1401c5690 (size=156) ============


undefined8 FUN_1401c5690(longlong param_1,int param_2)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  undefined8 uVar4;

  

  lVar2 = *(longlong *)(param_1 + 0x110);

  lVar1 = lVar2 + ((longlong)param_2 + 0x10) * 0x18;

  FUN_140179b40(*(undefined8 *)(lVar2 + 0x10 + ((longlong)param_2 + 0x10) * 0x18));

  if (*(int *)(lVar1 + 4) == 0) {

    uVar4 = 0x800;

    if (param_2 == 0) {

      uVar4 = 0x10000;

    }

    uVar4 = FUN_1401c7e90(lVar2,param_2,uVar4,0);

  }

  else {

    uVar3 = *(int *)(lVar1 + 4) - 1;

    uVar4 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + (ulonglong)uVar3 * 8);

    *(uint *)(lVar1 + 4) = uVar3;

  }

  FUN_140179b60(*(undefined8 *)(lVar1 + 0x10));

  FUN_1401cb730(param_1,uVar4);

  return uVar4;

}




