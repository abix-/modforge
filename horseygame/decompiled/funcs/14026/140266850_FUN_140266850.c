// Address: 0x140266850
// Ghidra name: FUN_140266850
// ============ 0x140266850 FUN_140266850 (size=888) ============


undefined8 FUN_140266850(undefined8 *param_1,undefined8 param_2,longlong param_3,int param_4)



{

  undefined8 uVar1;

  longlong lVar2;

  int iVar3;

  longlong lVar4;

  ulonglong uVar5;

  byte bVar6;

  

  uVar1 = FUN_140149300();

  if (*(int *)(*(longlong *)*param_1 + 0x8c) < 1) {

    FUN_140265350(param_1);

    if ((*(int *)(param_1 + 7) != 1) && (*(int *)(param_1 + 7) != 2)) {

      return 1;

    }

  }

  lVar2 = FUN_1401581c0(*(undefined4 *)((longlong)param_1 + 0xc));

  if (lVar2 == 0) {

    return 0;

  }

  if (*(int *)(param_1 + 0x1c) != 0) {

    FUN_14012e080(7,"GIP: Discarding early input report");

    *(undefined4 *)(param_1 + 0x1c) = 0;

    return 1;

  }

  if (param_4 < 0xe) {

    FUN_14012e080(7,"GIP: Discarding too-short input report");

    return 0;

  }

  FUN_140266cc0(param_1,lVar2,uVar1,param_3,param_4);

  iVar3 = *(int *)((longlong)param_1 + 0x144);

  if (iVar3 == 0) {

LAB_140266954:

    FUN_140266690(param_1,lVar2,uVar1,param_3,param_4);

  }

  else if (iVar3 == 1) {

    FUN_140265420(param_1,lVar2,uVar1,param_3,param_4);

  }

  else {

    if (iVar3 != 3) goto LAB_140266954;

    FUN_140266490(param_1,lVar2,uVar1,param_3,param_4);

  }

  if ((*(byte *)((longlong)param_1 + 0x14c) & 4) != 0) {

    iVar3 = *(int *)(param_1 + 0x29);

    if (iVar3 == 1) {

      if (((param_4 < 0x1d) ||

          (bVar6 = *(byte *)(param_3 + 0x1c), *(byte *)((longlong)param_1 + 0x111) == bVar6)) ||

         ((bVar6 & 0x10) == 0)) goto LAB_140266ad7;

      FUN_14015ad00(uVar1,lVar2,*(undefined1 *)((longlong)param_1 + 0x155),bVar6 >> 1 & 1);

      FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x01',

                    *(byte *)(param_3 + 0x1c) >> 3 & 1);

      FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x02',

                    *(byte *)(param_3 + 0x1c) & 1);

      bVar6 = *(byte *)(param_3 + 0x1c) >> 2 & 1;

    }

    else {

      if ((iVar3 - 3U < 2) && (0xe < param_4)) {

        lVar4 = 0x14;

        if (*(byte *)((longlong)param_1 + 0x103) == *(byte *)(param_3 + 0xe)) {

          lVar4 = 0x14;

          if (iVar3 == 3) {

            lVar4 = 0xf;

          }

          if (*(char *)(lVar4 + 0xf5 + (longlong)param_1) == *(char *)(lVar4 + param_3))

          goto LAB_140266b3a;

        }

        else if (iVar3 == 3) {

          lVar4 = 0xf;

        }

        if ((*(byte *)(lVar4 + param_3) & 3) == 0) {

          FUN_14015ad00(uVar1,lVar2,*(undefined1 *)((longlong)param_1 + 0x155),

                        *(byte *)(param_3 + 0xe) & 1);

          FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x01',

                        *(byte *)(param_3 + 0xe) >> 1 & 1);

          FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x02',

                        *(byte *)(param_3 + 0xe) >> 2 & 1);

          bVar6 = *(byte *)(param_3 + 0xe) >> 3 & 1;

          goto LAB_140266b23;

        }

      }

LAB_140266ad7:

      FUN_14015ad00(uVar1,lVar2,*(undefined1 *)((longlong)param_1 + 0x155),0);

      FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x01',0);

      FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x02',0);

      bVar6 = 0;

    }

LAB_140266b23:

    FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x03',bVar6);

  }

LAB_140266b3a:

  if (((*(uint *)((longlong)param_1 + 0x14c) & 1) != 0) && (0x1f < param_4)) {

    if ((*(uint *)((longlong)param_1 + 0x14c) & 8) == 0) {

      iVar3 = -0x12;

    }

    else {

      if (param_4 < 0x28) goto LAB_140266b8f;

      iVar3 = -0x1a;

    }

    iVar3 = param_4 + iVar3;

    if ((0xd < iVar3) &&

       (bVar6 = *(byte *)(iVar3 + param_3),

       *(byte *)((longlong)iVar3 + 0xf5 + (longlong)param_1) != bVar6)) {

      FUN_14015ad00(uVar1,lVar2,*(undefined1 *)((longlong)param_1 + 0x154),bVar6 & 1);

    }

  }

LAB_140266b8f:

  uVar5 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar5 = (longlong)param_4;

  }

  FUN_1402f8e20((longlong)param_1 + 0xf5,param_3,uVar5);

  return 1;

}




