// Address: 0x14026d850
// Ghidra name: FUN_14026d850
// ============ 0x14026d850 FUN_14026d850 (size=240) ============


ulonglong FUN_14026d850(longlong param_1)



{

  undefined8 uVar1;

  int iVar2;

  ulonglong in_RAX;

  longlong lVar3;

  undefined1 local_48 [64];

  

  uVar1 = *(undefined8 *)(param_1 + 0x70);

  if (*(int *)(param_1 + 0x8c) < 1) {

    return in_RAX & 0xffffffffffffff00;

  }

  lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);

  while (0 < iVar2) {

    if (lVar3 != 0) {

      if (iVar2 == 10) {

        FUN_14026ddb0(lVar3,uVar1,local_48,10);

      }

      else {

        FUN_14026d940();

      }

    }

    iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);

  }

  if (iVar2 < 0) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

  return (ulonglong)(byte)((byte)((uint)iVar2 >> 0x1f) ^ 1);

}




