// Address: 0x14026e8a0
// Ghidra name: FUN_14026e8a0
// ============ 0x14026e8a0 FUN_14026e8a0 (size=253) ============


ulonglong FUN_14026e8a0(longlong param_1)



{

  undefined8 uVar1;

  uint uVar2;

  ulonglong in_RAX;

  longlong lVar3;

  undefined1 local_48 [64];

  

  uVar1 = *(undefined8 *)(param_1 + 0x70);

  if (*(int *)(param_1 + 0x8c) < 1) {

    return in_RAX & 0xffffffffffffff00;

  }

  lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  uVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);

  while (0 < (int)uVar2) {

    if (lVar3 != 0) {

      if (uVar2 < 0x13) {

        if (uVar2 == 0x12) {

          FUN_14026f040(lVar3,uVar1,local_48,0x12);

        }

      }

      else {

        FUN_14026f360(lVar3,uVar1,local_48,uVar2);

      }

    }

    uVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);

  }

  if ((int)uVar2 < 0) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

  return (ulonglong)(byte)((byte)(uVar2 >> 0x1f) ^ 1);

}




