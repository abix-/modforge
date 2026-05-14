// Address: 0x140272910
// Ghidra name: FUN_140272910
// ============ 0x140272910 FUN_140272910 (size=598) ============


byte FUN_140272910(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  undefined8 uVar6;

  int iVar7;

  ulonglong uVar8;

  char local_98;

  undefined1 local_97;

  undefined1 local_96 [126];

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  uVar8 = 0;

  iVar7 = 0;

  uVar4 = FUN_140149350();

  uVar5 = uVar8;

  if (0 < *(int *)(param_1 + 0x8c)) {

    uVar5 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  }

  iVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_98,0x80,0);

  while (0 < iVar3) {

    uVar6 = FUN_140149300();

    cVar2 = FUN_140273be0(lVar1,&local_98,iVar3);

    if (cVar2 != '\0') {

      uVar8 = (ulonglong)((int)uVar8 + 1);

      *(ulonglong *)(lVar1 + 0x60) = uVar4;

      if (uVar5 != 0) {

        if (local_98 == '\x01') {

          if ((iVar3 == 10) || (iVar3 == 0x4e)) {

            FUN_140272cb0(uVar5,*(undefined8 *)(param_1 + 0x80),lVar1,&local_97,uVar6);

          }

          else if (*(char *)(lVar1 + 0x11) == '\0') {

            FUN_140272fd0(uVar5,*(undefined8 *)(param_1 + 0x80),lVar1,&local_97,uVar6);

          }

          else {

            FUN_1402731e0();

          }

        }

        else if (local_98 == '1') {

          FUN_140274470(lVar1);

          if (*(char *)(lVar1 + 0x11) == '\0') {

            FUN_140272fd0(uVar5,*(undefined8 *)(param_1 + 0x80),lVar1,local_96,uVar6);

          }

          else {

            FUN_1402731e0();

          }

          if (*(int *)(lVar1 + 0x74) == 1) {

            FUN_140272c30(lVar1);

          }

        }

      }

    }

    iVar7 = (int)uVar8;

    iVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_98,0x80,0);

  }

  if (*(char *)(param_1 + 0x54) != '\0') {

    if (iVar7 == 0) {

      if (*(longlong *)(lVar1 + 0x60) + 500U <= uVar4) {

        FUN_140274270(param_1);

        *(ulonglong *)(lVar1 + 0x60) = uVar4;

      }

    }

    else if ((*(int *)(param_1 + 0x8c) == 0) &&

            (cVar2 = FUN_140207f20(*(undefined8 *)(param_1 + 0x28)), cVar2 == '\0')) {

      FUN_140208110(param_1,0);

    }

  }

  if (*(char *)(lVar1 + 0x10) == '\0') {

    if (iVar7 != 0) goto LAB_140272b42;

  }

  else {

    if (iVar7 != 0) {

      if (*(int *)(param_1 + 0x8c) == 0) {

        FUN_140208110(param_1,0);

      }

      goto LAB_140272b42;

    }

    if ((0 < *(int *)(param_1 + 0x8c)) && (*(longlong *)(lVar1 + 0x60) + 500U <= uVar4)) {

      FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

    }

  }

  if ((iVar3 < 0) && (0 < *(int *)(param_1 + 0x8c))) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

LAB_140272b42:

  return (byte)((uint)iVar3 >> 0x1f) ^ 1;

}




