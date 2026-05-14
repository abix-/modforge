// Address: 0x14027b670
// Ghidra name: FUN_14027b670
// ============ 0x14027b670 FUN_14027b670 (size=386) ============


ulonglong FUN_14027b670(longlong param_1)



{

  longlong lVar1;

  uint uVar2;

  ulonglong in_RAX;

  longlong lVar3;

  char local_48 [64];

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(int *)(param_1 + 0x8c) < 1) {

    return in_RAX & 0xffffffffffffff00;

  }

  lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  uVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);

  while (0 < (int)uVar2) {

    if (*(longlong *)(lVar1 + 0x50) == 0) {

      if (*(char *)(param_1 + 0x54) == '\0') {

        FUN_14027d040(lVar3,lVar1,local_48,uVar2);

      }

      else if (local_48[0] == '\x01') {

        if ((lVar3 != 0) && (0xf < uVar2)) {

          FUN_14027bd80(lVar3,lVar1,local_48,uVar2);

        }

      }

      else if (local_48[0] == '\x02') {

        if (lVar3 != 0) {

          FUN_14027bd30(lVar3,lVar1,local_48,uVar2);

        }

      }

      else if ((local_48[0] == '\x04') && (lVar3 != 0)) {

        FUN_14027b980(lVar3,lVar1,local_48,uVar2);

      }

    }

    else {

      if (lVar3 == 0) break;

      FUN_14027c000(lVar3,lVar1,local_48,uVar2);

    }

    uVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0);

  }

  FUN_14027cc10(lVar1);

  FUN_14027cca0(lVar1);

  if ((int)uVar2 < 0) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

  return (ulonglong)(byte)((byte)(uVar2 >> 0x1f) ^ 1);

}




