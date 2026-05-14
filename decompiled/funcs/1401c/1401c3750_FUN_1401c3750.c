// Address: 0x1401c3750
// Ghidra name: FUN_1401c3750
// ============ 0x1401c3750 FUN_1401c3750 (size=133) ============


ulonglong FUN_1401c3750(longlong param_1)



{

  longlong lVar1;

  byte bVar2;

  int iVar3;

  ulonglong uVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  iVar3 = (**(code **)(**(longlong **)(param_1 + 0x120) + 0x48))();

  if (iVar3 < 0) {

    uVar4 = FUN_1401cb240(lVar1,"Failed to close command list!",iVar3);

    return uVar4 & 0xffffffffffffff00;

  }

  *(undefined1 *)(param_1 + 0x130) = 0;

  FUN_140179b40(*(undefined8 *)(lVar1 + 0x210));

  bVar2 = FUN_1401c6970(lVar1,param_1,1);

  FUN_140179b60(*(undefined8 *)(lVar1 + 0x210));

  return (ulonglong)bVar2;

}




