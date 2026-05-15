// Address: 0x140274860
// Ghidra name: FUN_140274860
// ============ 0x140274860 FUN_140274860 (size=470) ============


ulonglong FUN_140274860(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  ulonglong in_RAX;

  longlong lVar3;

  ulonglong uVar4;

  undefined8 uVar5;

  char local_48;

  char local_47;

  undefined1 local_45;

  undefined1 local_43;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(int *)(param_1 + 0x8c) < 1) {

    return in_RAX & 0xffffffffffffff00;

  }

  lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x40,0);

  while (0 < iVar2) {

    if (lVar3 != 0) {

      if (local_48 == '\x01') {

        if (iVar2 == 0x10) {

          FUN_140274a40();

        }

        else {

          FUN_140274d60(lVar3,lVar1,&local_48,iVar2);

        }

      }

      else if (local_48 == '\x02') {

        FUN_140275050(lVar3,lVar1,&local_48,iVar2);

      }

      else if (local_48 == '\x03') {

        if (local_47 == '\a') {

          *(undefined1 *)(lVar1 + 3) = 1;

          *(undefined1 *)(lVar1 + 4) = local_43;

          FUN_140275280(lVar3,lVar1);

        }

        else if (local_47 == '9') {

          *(undefined1 *)(lVar1 + 0x10) = 0;

          FUN_140275210(param_1);

        }

        else if (local_47 == ':') {

          *(undefined1 *)(lVar1 + 1) = 1;

          *(undefined1 *)(lVar1 + 2) = local_45;

          FUN_140275280(lVar3,lVar1);

        }

      }

    }

    iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x40,0);

  }

  if ((lVar3 != 0) && (uVar4 = FUN_140149350(), *(longlong *)(lVar1 + 8) + 60000U <= uVar4)) {

    uVar5 = FUN_140149350();

    *(undefined8 *)(lVar1 + 8) = uVar5;

    FUN_140275130(param_1,7,0,0);

  }

  if (((*(char *)(lVar1 + 0x12) != '\0') || (*(char *)(lVar1 + 0x13) != '\0')) &&

     (lVar3 = *(longlong *)(lVar1 + 0x18), uVar4 = FUN_140149350(), lVar3 + 500U <= uVar4)) {

    *(undefined1 *)(lVar1 + 0x11) = 1;

    FUN_140275210(param_1);

  }

  if (iVar2 < 0) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

  return (ulonglong)(byte)((byte)((uint)iVar2 >> 0x1f) ^ 1);

}




