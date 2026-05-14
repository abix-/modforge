// Address: 0x140283780
// Ghidra name: FUN_140283780
// ============ 0x140283780 FUN_140283780 (size=268) ============


ulonglong FUN_140283780(longlong param_1)



{

  short sVar1;

  undefined8 uVar2;

  int iVar3;

  ulonglong in_RAX;

  longlong lVar4;

  undefined1 local_48 [64];

  

  uVar2 = *(undefined8 *)(param_1 + 0x70);

  if (*(int *)(param_1 + 0x8c) < 1) {

    return in_RAX & 0xffffffffffffff00;

  }

  lVar4 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  iVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);

  while (0 < iVar3) {

    if (lVar4 != 0) {

      sVar1 = *(short *)(param_1 + 0x22);

      if (sVar1 == 0x17) {

        FUN_140283da0(lVar4,uVar2,local_48,iVar3);

      }

      else if (((ushort)(sVar1 - 0x1cU) < 2) || (sVar1 == 6)) {

        FUN_140283890(lVar4,uVar2,local_48,iVar3);

      }

    }

    iVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);

  }

  if (iVar3 < 0) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

  return (ulonglong)(byte)((byte)((uint)iVar3 >> 0x1f) ^ 1);

}




